#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "logic.h"

long double text_to_number(const char *text, long double x, int dtf) {
  long double result = 0;
  if (dtf == 1 && text[0] == 'x') {
    result = x;
  } else {
    result = atof(text);
  }
  return result;
}

int check_error(int num) {
  int error = 0;
  if (num == 0) {
    error = 1;
  }
  return error;
}

int check_error_2(int num, int num2) {
  int error = 0;
  if (num == 0 || num2 == 0) {
    error = 1;
  }
  return error;
}

long double calculation(const char *expression, long double x, int dtf,
                        int *error) {
  int length = strlen(expression);
  long double result = 0;
  locals num;
  num.len = 1;
  for (int i = 0; i < length; i++) {
    if (expression[i] == ' ') {
      continue;
    }
    if (is_number(expression[i])) {
      num.expression[num.len] = text_to_number(&expression[i], x, dtf);
      num.len++;
      for (; is_number(expression[i]); i++)
        ;
    } else {
      if (expression[i] == '~') {
        if ((*error = check_error(num.len - 1)) != 0) {
          break;
        }
        num.expression[num.len - 1] = -num.expression[num.len - 1];
      } else if (expression[i] == '+') {
        if ((*error = check_error_2(num.len - 1, num.len - 2)) != 0) {
          break;
        }
        result = num.expression[num.len - 2] + num.expression[num.len - 1];
        num.expression[num.len - 2] = result;
        num.len--;
      } else if (expression[i] == '-') {
        if ((*error = check_error_2(num.len - 1, num.len - 2)) != 0) {
          break;
        }
        result = num.expression[num.len - 2] - num.expression[num.len - 1];
        num.expression[num.len - 2] = result;
        num.len--;
      } else if (expression[i] == '*') {
        if ((*error = check_error_2(num.len - 1, num.len - 2)) != 0) {
          break;
        }
        result = num.expression[num.len - 2] * num.expression[num.len - 1];
        num.expression[num.len - 2] = result;
        num.len--;
      } else if (expression[i] == '/') {
        if ((*error = check_error_2(num.len - 1, num.len - 2)) != 0) {
          break;
        }
        result = num.expression[num.len - 2] / num.expression[num.len - 1];
        num.expression[num.len - 2] = result;
        num.len--;
      } else if (expression[i] == '^') {
        if ((*error = check_error_2(num.len - 1, num.len - 2)) != 0) {
          break;
        }
        result = pow(num.expression[num.len - 2], num.expression[num.len - 1]);
        num.expression[num.len - 2] = result;
        num.len--;
      } else if (expression[i] == 's') {
        if ((*error = check_error(num.len - 1)) != 0) {
          break;
        }
        result = sinl(num.expression[num.len - 1]);
        num.expression[num.len - 1] = result;
      } else if (expression[i] == 'c') {
        if ((*error = check_error(num.len - 1)) != 0) {
          break;
        }
        result = cosl(num.expression[num.len - 1]);
        num.expression[num.len - 1] = result;
      } else if (expression[i] == 'q') {
        if ((*error = check_error(num.len - 1)) != 0) {
          break;
        }
        result = sqrtl(num.expression[num.len - 1]);
        num.expression[num.len - 1] = result;
      } else if (expression[i] == 'L') {
        if ((*error = check_error(num.len - 1)) != 0) {
          break;
        }
        result = log10l(num.expression[num.len - 1]);
        num.expression[num.len - 1] = result;
      } else if (expression[i] == 'l') {
        if ((*error = check_error(num.len - 1)) != 0) {
          break;
        }
        result = logl(num.expression[num.len - 1]);
        num.expression[num.len - 1] = result;
      } else if (expression[i] == 'S') {
        if ((*error = check_error(num.len - 1)) != 0) {
          break;
        }
        result = asinl(num.expression[num.len - 1]);
        num.expression[num.len - 1] = result;
      } else if (expression[i] == 'C') {
        if ((*error = check_error(num.len - 1)) != 0) {
          break;
        }
        result = acosl(num.expression[num.len - 1]);
        num.expression[num.len - 1] = result;
      } else if (expression[i] == 'T') {
        if ((*error = check_error(num.len - 1)) != 0) {
          break;
        }
        result = atanl(num.expression[num.len - 1]);
        num.expression[num.len - 1] = result;
      } else if (expression[i] == 't') {
        if ((*error = check_error(num.len - 1)) != 0) {
          break;
        }
        result = tanl(num.expression[num.len - 1]);
        num.expression[num.len - 1] = result;
      } else if (expression[i] == 'm') {
        if ((*error = check_error_2(num.len - 1, num.len - 2)) != 0) {
          break;
        }
        result =
            fmodl(num.expression[num.len - 2], num.expression[num.len - 1]);
        num.expression[num.len - 2] = result;
        num.len--;
      }
    }
  }
  result = num.expression[1];
  return result;
}
