#include "parse.h"

#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *parse_opt(char **argv, int argc, char *option, int *k) {
  for (int i = 1; i < argc; i++) {
    if (argv[i][0] != '-') {
      strcpy(option, argv[i]);
      *k = i + 1;
      break;
    }
  }
  return option;
}

int file_count(char **argv, int argc) {
  int count_files = 0;
  for (int i = 1; i < argc; i++) {
    if ((strstr(argv[i], "e") != NULL && argv[i][0] == '-') ||
        (strstr(argv[i], "f") != NULL && argv[i][0] == '-')) {
      i++;
      continue;
    }
    if (argv[i][0] != '-') count_files++;
  }
  return count_files;
}

int files_pattern(char *path, pattern *patterns) {
  char buff[SIZE_BUFF];
  int f_p = 1;
  FILE *file;
  file = fopen(path, "r");
  if (file == NULL) f_p = 0;
  if (file != NULL) {
    while ((fgets(buff, SIZE_BUFF, file)) != NULL) {
      patterns->pattern_mx[patterns->count] = malloc(sizeof(char) * SIZE_BUFF);
      strcpy(patterns->pattern_mx[patterns->count], buff);
      patterns->count++;
      if (patterns->count == patterns->cl_str)
        patterns->pattern_mx =
            realloc(patterns->pattern_mx, patterns->cl_str += 5);
    }
    fclose(file);
  }
  return f_p;
}

bool parse_flags(char **argv, flags *flags_is_on, int argc, pattern *patterns) {
  bool fl = false;
  int ch = 0;
  int f_p;
  patterns->pattern_mx = malloc(sizeof(char *) * patterns->cl_str);
  for (int i = 0; i < patterns->cl_str; i++) patterns->pattern_mx[i] = NULL;
  while ((ch = getopt_long(argc, argv, "e:ivclnhsf:o", NULL, NULL)) != -1) {
    if (fl == 2) break;
    switch (ch) {
      case 'e':
        flags_is_on->e = true;
        patterns->pattern_mx[patterns->count] =
            malloc(sizeof(char) * SIZE_BUFF);
        strcpy(patterns->pattern_mx[patterns->count], optarg);
        patterns->count++;
        if (patterns->count == patterns->cl_str)
          patterns->pattern_mx =
              realloc(patterns->pattern_mx, patterns->cl_str += 5);
        fl = true;
        break;
      case 'f':
        flags_is_on->f = true;
        f_p = files_pattern(optarg, patterns);
        fl = f_p;
        if (!f_p) {
          fprintf(stderr, "grep: %s: No such file of directory\n", optarg);
          fl = 2;
        }
        break;
      case 'i':
        flags_is_on->i = true;
        fl = true;
        break;
      case 'v':
        flags_is_on->v = true;
        fl = true;
        break;
      case 'c':
        flags_is_on->c = true;
        fl = true;
        break;
      case 'l':
        flags_is_on->l = true;
        fl = true;
        break;
      case 'n':
        flags_is_on->n = true;
        fl = true;
        break;
      case 'h':
        flags_is_on->h = true;
        fl = true;
        break;
      case 's':
        flags_is_on->s = true;
        fl = true;
        break;
      case 'o':
        flags_is_on->o = true;
        fl = true;
        break;
      default:
        fl = 2;
        break;
    }
  }
  return fl;
}

bool rex(char *buff, char *ptr, flags *pat) {
  int value;
  bool res = false;
  regex_t reegex;
  if (!pat->i) value = regcomp(&reegex, ptr, 0);
  if (pat->i) value = regcomp(&reegex, ptr, REG_ICASE);
  if (value == 0) {
    if (regexec(&reegex, buff, 0, NULL, 0) == 0) res = true;
  }
  regfree(&reegex);
  return res;
}