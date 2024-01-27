#include <stdlib.h>

#include "logic.h"
#include "parse.h"

int main(int argc, char **argv) {
  if (argc > 1) {
    int error;
    bool tr_fl;
    flags flags_is_on = {0};
    pattern patterns;
    patterns.cl_str = 10;
    patterns.count = 0;
    tr_fl = parse_flags(argv, &flags_is_on, argc, &patterns);
    if (tr_fl != 2) {
      if (tr_fl) {
        error = grep_work_is_flags(argv, argc, &patterns, &flags_is_on);
        if (!error) printf("ERROR");
      }
      if (!tr_fl) {
        error = grep_work_not_flags(argv, argc);
        if (error) printf("ERROR");
      }
    }
    for (int i = 0; patterns.pattern_mx[i] != NULL; i++)
      free(patterns.pattern_mx[i]);
    free(patterns.pattern_mx);
  }
  return 0;
}