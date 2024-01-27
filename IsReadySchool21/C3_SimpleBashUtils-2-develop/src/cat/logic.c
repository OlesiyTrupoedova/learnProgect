#include "logic.h"

#include <stdio.h>

#include "parse.h"

void cook_cat(arguments *flags, FILE *file) {
  int ch;
  char flag_b = '\n';
  int gobble, count;
  count = 1;
  gobble = 0;

  for (; (ch = getc(file)) != EOF; flag_b = ch) {
    if (flag_b == '\n') {
      if (flags->s) {
        if (ch == '\n') {
          if (gobble) continue;
          gobble = 1;
        } else
          gobble = 0;
      }
      if (flags->n) {
        printf("%6d\t", count);
        count++;
      }
      if (flags->b) {
        if (ch != '\n') {
          printf("%6d\t", count);
          count++;
        }
      }
    }
    if (ch == '\n') {
      if (flags->e) printf("$");
    }
    if (ch == '\t') {
      if (flags->t) {
        printf("^I");
        continue;
      }
    }
    if (flags->v) {
      if (ch >= 0 && ch <= 31 && ch != '\n' && ch != '\t') {
        printf("^%c", ch + 64);
        continue;
      }
      if (ch == 127) {
        printf("^?");
        continue;
      }
      if (ch >= 128 && ch <= 159) {
        printf("M-^%c", ch - 64);
        continue;
      }
    }

    putchar(ch);
  }
}