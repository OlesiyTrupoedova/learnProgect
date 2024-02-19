#include <stdio.h>

#include "object.h"

#ifndef PARSE_H
#define PARSE_H

int parse(char *path, object *obj);
void parse_vertex(char *line, object *obj);
void parse_polygon(char *line, object *obj);

#endif  // PARSE_H
