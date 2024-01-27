#ifndef PARSE_H
#define PARSE_H

#define bool char
#define true 1
#define false 0

typedef struct {
  bool s;
  bool e;
  bool t;
  bool v;
  bool n;
  bool b;
} arguments;
int parse(char **argv, arguments *flags, int argc);
#endif