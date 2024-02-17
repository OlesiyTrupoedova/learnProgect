#ifndef PARSE_H
#define PARSE_H

#define bool char
#define true 1
#define false 0
#define SIZE_BUFF 1000

typedef struct {
  bool e;
  bool i;
  bool v;
  bool c;
  bool l;
  bool n;
  bool h;
  bool s;
  bool f;
  bool o;
} flags;

typedef struct {
  char **pattern_mx;
  int count;
  int cl_str;
} pattern;
bool parse_flags(char **argv, flags *flags_is_on, int argc, pattern *patterns);
int file_count(char **argv, int argc);
bool rex(char *buff, char *ptr, flags *pat);
char *parse_opt(char **argv, int argc, char *option, int *k);
int files_pattern(char *path, pattern *patterns);
#endif