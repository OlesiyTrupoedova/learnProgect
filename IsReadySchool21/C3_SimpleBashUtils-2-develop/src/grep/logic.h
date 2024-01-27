#include <stdio.h>

#include "parse.h"

#ifndef LOGIC_H
#define LOGIC_H

int not_e_f(char **argv, int *count_files, pattern *patterns,
            int *file_start_search, int argc);
void logic(char **argv, pattern *patterns, flags *flags_is_on, int count_files,
           FILE *file, int i);
int o_flag(char *str, pattern *patterns, flags *flag);
int grep_work_not_flags(char **argv, int argc);
int grep_work_is_flags(char **argv, int argc, pattern *patterns,
                       flags *flags_is_on);

#endif