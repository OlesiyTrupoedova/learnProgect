#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "logic.h"
#include "parse.h"

int main(int argc, char **argv) {
  FILE *file = NULL;
  arguments flags = {false};
  int count_flags = parse(argv, &flags, argc);
  if (count_flags == -1) {
    return 0;
  }
  char ch;
  if (argc == 1) {
    return 0;
  }

  if (!count_flags) {
    for (int i = 1; i < argc; i++) {
      file = fopen(argv[i], "r");
      if (file == NULL) {
        fprintf(stderr, "cat: %s: No such file or directory\n", argv[i]);
        continue;
      }
      while ((ch = getc(file)) != EOF) printf("%c", ch);
      fclose(file);
    }
  } else {
    for (int i = count_flags + 1; i < argc; i++) {
      file = fopen(argv[i], "r");
      if (file == NULL) {
        fprintf(stderr, "cat: %s: No such file or directory\n", argv[i]);
        continue;
      }
      cook_cat(&flags, file);
      fclose(file);
    }
  }
}
