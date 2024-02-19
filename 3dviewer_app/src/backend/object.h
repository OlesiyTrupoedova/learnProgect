#ifndef POINT_H
#define POINT_H

typedef struct point {
  float x;
  float y;
  float z;
} point;

typedef struct polygon {
  int *polygons;
  int polygons_count;
} polygon;

typedef struct object {
  int vertexes_amount;
  int polygons_amount;
  point *vertexes;
  polygon *polygons;
} object;

#endif
