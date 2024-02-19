#include "parse.h"

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "object.h"

int parse(char *path, object *obj) {
  setlocale(LC_NUMERIC, "C");
  FILE *file;
  file = fopen(path, "r");
  if (file == NULL) {
    return 1;
  }
  char line[1024];
  int size_polygon = 1000;
  int size_vertex = 1000;
  obj->vertexes = malloc(sizeof(point) * size_vertex);
  obj->polygons = malloc(sizeof(polygon) * size_polygon);
  obj->vertexes_amount = 0;
  obj->polygons_amount = 0;
  while (fgets(line, 1024, file) != NULL) {
    if (line[0] == 'v' && line[1] == ' ') {
      if (obj->vertexes_amount >= size_vertex) {
        obj->vertexes = realloc(obj->vertexes, sizeof(point) * size_vertex * 2);
        size_vertex *= 2;
      }
      parse_vertex(line, obj);
    } else if (line[0] == 'f') {
      if (obj->polygons_amount >= size_polygon) {
        obj->polygons =
            realloc(obj->polygons, sizeof(polygon) * size_polygon * 2);
        size_polygon *= 2;
      }
      parse_polygon(line, obj);
    }
  }
  fclose(file);
  return 0;
}

void parse_vertex(char *line, object *obj) {
  float x, y, z;
  sscanf(line, "v %f %f %f", &x, &y, &z);
  obj->vertexes[obj->vertexes_amount].x = x;
  obj->vertexes[obj->vertexes_amount].y = y;
  obj->vertexes[obj->vertexes_amount].z = z;
  obj->vertexes_amount++;
}

void parse_polygon(char *line, object *obj) {
  char *token = strtok(line, " ");
  token = strtok(NULL, " ");
  int size_polygon = 3;
  int *polygons = malloc(sizeof(int) * size_polygon);
  int polygons_count = 0;
  while (token != NULL) {
    polygons[polygons_count] = atoi(token) - 1;
    polygons_count++;
    if (polygons_count >= size_polygon) {
      polygons = realloc(polygons, sizeof(int) * size_polygon * 2);
    }
    size_polygon *= 2;
    token = strtok(NULL, " ");
  }
  obj->polygons[obj->polygons_amount].polygons = polygons;
  obj->polygons[obj->polygons_amount].polygons_count = polygons_count;
  obj->polygons_amount++;
}
