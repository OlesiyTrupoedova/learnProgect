#include <math.h>
#include <stdlib.h>

#include "action_with_obgect.h"
#include "object.h"

#define MOVE_X 0
#define MOVE_Y 1
#define MOVE_Z 2

void remove_object(object *obj) {
  for (int i = 0; i < obj->polygons_amount; i++) {
    free(obj->polygons[i].polygons);
  }
  free(obj->polygons);
  free(obj->vertexes);
}

void skale_object(object *obj, float value) {
  for (int i = 0; i < obj->vertexes_amount; i++) {
    obj->vertexes[i].x *= value;
    obj->vertexes[i].y *= value;
    obj->vertexes[i].z *= value;
  }
}

void normalize(object *obj) {
  float maxX, minX, maxY, minY, maxZ, minZ;
  maxX = minX = maxY = minY = maxZ = minZ = 0;
  for (int i = 0; i < obj->vertexes_amount; i++) {
    maxX = obj->vertexes[i].x > maxX ? obj->vertexes[i].x : maxX;
    minX = obj->vertexes[i].x < minX ? obj->vertexes[i].x : minX;
    maxY = obj->vertexes[i].y > maxY ? obj->vertexes[i].y : maxY;
    minY = obj->vertexes[i].y < minY ? obj->vertexes[i].y : minY;
    maxZ = obj->vertexes[i].z > maxZ ? obj->vertexes[i].z : maxZ;
    minZ = obj->vertexes[i].z < minZ ? obj->vertexes[i].z : minZ;
  }
  float centeringX = (maxX + minX) / 2;
  float centeringY = (maxY + minY) / 2;
  float centeringZ = (maxZ + minZ) / 2;
  for (int i = 0; i < obj->vertexes_amount; i++) {
    obj->vertexes[i].x -= centeringX;
    obj->vertexes[i].y -= centeringY;
    obj->vertexes[i].z -= centeringZ;
  }
  float X = maxX - minX;
  float Y = maxY - minY;
  float Z = maxZ - minZ;
  float dmax = X > Y ? X : Y;
  dmax = Z > dmax ? Z : dmax;
  float skale = 1.4 / dmax;
  skale_object(obj, skale);
}

void move_object(object *obj, float value, int move) {
  if (move == MOVE_X) {
    for (int i = 0; i < obj->vertexes_amount; i++) {
      obj->vertexes[i].x += value;
    }
  } else if (move == MOVE_Y) {
    for (int i = 0; i < obj->vertexes_amount; i++) {
      obj->vertexes[i].y += value;
    }
  } else if (move == MOVE_Z) {
    for (int i = 0; i < obj->vertexes_amount; i++) {
      obj->vertexes[i].z += value;
    }
  }
}

// y':=y*cos(L)+z*sin(L) ;
// z':=y*sin(L)+z*cos(L) ;

void rotation_by_oy(object *obj, float angle) {
  float temp_y = 0;
  float temp_z = 0;
  float sin_angle = sin(angle);
  float cos_angle = cos(angle);
  for (int i = 0; i < obj->vertexes_amount; i++) {
    temp_y = obj->vertexes[i].y;
    temp_z = obj->vertexes[i].z;
    obj->vertexes[i].y = temp_y * cos_angle - temp_z * sin_angle;
    obj->vertexes[i].z = temp_y * sin_angle + temp_z * cos_angle;
  }
}

// x'=x*cos(L)+z*sin(L);
// z'=-x*sin(L)+z*cos(L);

void rotation_by_ox(object *obj, float angle) {
  float temp_x = 0;
  float temp_z = 0;
  float sin_angle = sin(angle);
  float cos_angle = cos(angle);
  for (int i = 0; i < obj->vertexes_amount; i++) {
    temp_x = obj->vertexes[i].x;
    temp_z = obj->vertexes[i].z;
    obj->vertexes[i].x = temp_x * cos_angle + temp_z * sin_angle;
    obj->vertexes[i].z = -temp_x * sin_angle + temp_z * cos_angle;
  }
}

// x'=x*cos(L)-y*sin(L);
// y'=-x*sin(L)+y*cos(L);

void rotation_by_oz(object *obj, float angle) {
  float temp_x = 0;
  float temp_y = 0;
  float sin_angle = sin(angle);
  float cos_angle = cos(angle);
  for (int i = 0; i < obj->vertexes_amount; i++) {
    temp_x = obj->vertexes[i].x;
    temp_y = obj->vertexes[i].y;
    obj->vertexes[i].x = temp_x * cos_angle - temp_y * sin_angle;
    obj->vertexes[i].y = temp_x * sin_angle + temp_y * cos_angle;
  }
}
