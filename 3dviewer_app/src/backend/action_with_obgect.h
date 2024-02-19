#ifndef ACTION_WITH_OBGECT_H
#define ACTION_WITH_OBGECT_H
#include "object.h"

void remove_object(object *obj);
void normalize(object *obj);
void skale_object(object *obj, float value);
void move_object(object *obj, float value, int move);

void rotation_by_ox(object *obj, float angle);
void rotation_by_oy(object *obj, float angle);
void rotation_by_oz(object *obj, float angle);

#endif  // ACTION_WITH_OBGECT_H
