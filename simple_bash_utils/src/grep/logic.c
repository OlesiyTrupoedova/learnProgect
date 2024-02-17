#include "logic.h"

#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int not_e_f(char **argv, int *count_files, pattern *patterns,
            int *file_start_search, int argc) {
  int error = 1;
  int skip = 1;
  char *option = malloc(sizeof(char) * SIZE_BUFF);
  for (int i = 1; i < argc; i++) {
    if (argv[i][0] != '-') {
      if (skip) {
        skip = 0;
        continue;
      }
      *count_files = 1 + *count_files;
    }
  }
  if (*count_files < 1) {
    error = 0;
  } else {
    option = parse_opt(argv, argc, option, file_start_search);
    patterns->pattern_mx[patterns->count] = malloc(sizeof(char) * SIZE_BUFF);
    strcpy(patterns->pattern_mx[patterns->count], option);
    patterns->count++;
  }
  free(option);
  return error;
}

int o_flag(char *str, pattern *patterns, flags *flag) {
  regex_t regex;
  regmatch_t match[SIZE_BUFF];
  int skip = 0;
  char ptr[SIZE_BUFF];
  for (int i = 0; i < patterns->count; i++) {
    strcpy(ptr, patterns->pattern_mx[i]);
    if (regcomp(&regex, ptr, flag->i ? REG_ICASE : 0) == 0) {
      while ((regexec(&regex, str, SIZE_BUFF, match, 0) == 0)) {
        int start = match[0].rm_so;
        int end = match[0].rm_eo;
        if (!flag->v) printf("%.*s\n", end - start, str + start);
        str = str + end;
        skip++;
      }
    }
  }
  if (flag->v) skip = -1;
  regfree(&regex);
  return skip;
}

int grep_work_not_flags(char **argv, int argc) {
  int value;
  int error = 0;
  char buff[SIZE_BUFF];
  FILE *file;
  regex_t reegex;
  if (argv[1] != NULL) {
    value = regcomp(&reegex, argv[1], 0);
    if (value == 0) {
      if (argv[2] == NULL) {
        error = 1;
      } else {
        for (int i = 2; i < argc; i++) {
          file = fopen(argv[i], "r");
          if (file == NULL) {
            fprintf(stderr, "grep: %s: No such file of directory\n", argv[i]);
            continue;
          }
          while ((fgets(buff, SIZE_BUFF, file)) != NULL) {
            if ((regexec(&reegex, buff, 0, NULL, 0)) != 0) continue;
            printf("%s", buff);
          }
          fclose(file);
        }
      }
    }
  }
  regfree(&reegex);
  return error;
}

void logic(char **argv, pattern *patterns, flags *flags_is_on, int count_files,
           FILE *file, int i) {
  int l = false;
  int o_v_flag = 0;
  char buff[SIZE_BUFF];
  int skip = 1;
  char ptr[SIZE_BUFF];
  int count_c = 0, count_n = 0, flag_l = 0;
  count_c = count_n = 0;
  while ((fgets(buff, SIZE_BUFF, file)) != NULL) {
    count_n++;
    for (int k = 0; k < SIZE_BUFF; k++) {
      if (buff[k] == '\n') buff[k] = '\0';
      if (buff[k] == '\0') break;
    }
    for (int j = 0; j < patterns->count; j++) {
      strcpy(ptr, patterns->pattern_mx[j]);
      skip = rex(buff, ptr, flags_is_on);
      if (flags_is_on->v) {
        skip = !skip;
        if (skip) continue;
        if (!skip) break;
      }

      if (skip) break;
    }
    if (flags_is_on->l && skip) {
      flag_l = true;
      break;
    }
    if (flags_is_on->l && !skip) {
      flag_l = false;
      continue;
    }

    if (skip) {
      if (flags_is_on->c) {
        count_c++;
        continue;
      }
      if (!flags_is_on->h && count_files > 1) printf("%s:", argv[i]);
      if (flags_is_on->n) printf("%d:", count_n);
      if (flags_is_on->o) o_v_flag = o_flag(buff, patterns, flags_is_on);
      if (!flags_is_on->o) {
        printf("%s", buff);
        printf("\n");
      }
      if (flags_is_on->o && o_v_flag == -1) {
        printf("%s", buff);
        printf("\n");
      }
    }
  }
  if (flag_l && flags_is_on->l && flags_is_on->c && count_files == 1)
    printf("1\n");
  if (flag_l && flags_is_on->l && flags_is_on->c && count_files > 1)
    printf("%s:1\n", argv[i]);
  if (flags_is_on->l && flag_l) {
    printf("%s\n", argv[i]);
    l = true;
  }
  if (!l) {
    if (flags_is_on->c) {
      if (flags_is_on->c && count_files > 1 && !flags_is_on->h)
        printf("%s:", argv[i]);
      printf("%d", count_c);
    }
    if (flags_is_on->c) printf("\n");
  }
}

int grep_work_is_flags(char **argv, int argc, pattern *patterns,
                       flags *flags_is_on) {
  FILE *file = NULL;
  int file_start_search = 1, count_files = 0, error = 1;
  if (!flags_is_on->e && !flags_is_on->f) {
    error = not_e_f(argv, &count_files, patterns, &file_start_search, argc);
  }
  if (error) {
    if (flags_is_on->e || flags_is_on->f) {
      count_files = file_count(argv, argc);
    }
    if (count_files != 0) {
      for (int i = file_start_search; i < argc; i++) {
        if ((strstr(argv[i], "e") != NULL && argv[i][0] == '-') ||
            (strstr(argv[i], "f") != NULL && argv[i][0] == '-')) {
          i++;
          continue;
        }
        if (argv[i][0] == '-') continue;
        file = fopen(argv[i], "r");
        if (file == NULL) {
          if (!flags_is_on->s)
            fprintf(stderr, "grep: %s: No such file or directory\n", argv[i]);
          continue;
        }
        logic(argv, patterns, flags_is_on, count_files, file, i);
        fclose(file);
      }
    }
  }
  return error;
}
