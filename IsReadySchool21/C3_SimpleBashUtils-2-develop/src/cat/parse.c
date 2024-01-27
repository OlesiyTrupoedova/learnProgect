#include "parse.h"

#include <stdio.h>
#include <string.h>

int parse(char **argv, arguments *flags, int argc) {
  char count_flags = 0;
  int skip, skip1, skip2;
  skip = skip1 = skip2 = 0;
  char *flag_b = "--number-nonblank";
  char *flag_n = "--number";
  char *flag_s = "--squeeze-blank";
  for (int i = 1; i < argc; i++) {
    if (argv[i][0] != '-') break;
    if (argv[i][0] == '-') count_flags++;
  }
  for (int i = 1; i <= count_flags; i++) {
    if (!strcmp(argv[i], flag_b)) {
      flags->b = true;
      skip = i;
    }
    if (!strcmp(argv[i], flag_n)) {
      flags->n = true;
      skip1 = i;
    }
    if (!strcmp(argv[i], flag_s)) {
      flags->s = true;
      skip2 = i;
    }
  }

  for (int i = 1; i <= count_flags; i++) {
    int len = strlen(argv[i]);
    if (skip == i) continue;
    if (skip1 == i) continue;
    if (skip2 == i) continue;
    for (int j = 0; j < len; j++) {
      if (argv[i][j] == '-') {
        continue;
      }
      switch (argv[i][j]) {
        case 'e':
          flags->e = true;
          flags->v = true;
          break;
        case 'n':
          flags->n = true;
          break;
        case 'E':
          flags->e = true;
          break;
        case 'b':
          flags->b = true;
          break;
        case 's':
          flags->s = true;
          break;
        case 't':
          flags->t = true;
          flags->v = true;
          break;
        case 'T':
          flags->t = true;
          break;
        case 'v':
          flags->v = true;
          break;
        default:
          fprintf(stderr, "cat: illegal option -- %c\n", argv[i][j]);
          fprintf(stderr, "usage: cat [-benstuv] [file ...]\n");
          count_flags = -1;
          break;
      }
    }
  }
  if (flags->b) flags->n = false;

  return count_flags;
}