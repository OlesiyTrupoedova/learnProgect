#include <stdio.h>
#include <string.h>

#include "logic.h"
int validate(char *expression) {
  int error = 0;
  int length = strlen(expression);
  error = validate_trigonometry(expression, length);
  if (!error) {
    error = staple_sequence(expression, length);
  }
  if (!error) {
    error = sign_sequence(expression, length);
  }

  return error;
}

int check_mass_is_correct_br(char mass[2]) {
  int error = 0;
  if (sign(mass[0]) && sign(mass[1])) {
    error = 1;
  }
  if (is_trig(mass[0])) {
    error = 1;
  }
  if (!is_trig(mass[1]) && sign(mass[0])) {
    error = 1;
  }
  return error;
}

int check_beginning_of_line(char *expression, int length, int *j) {
  int error = 0;
  if (expression[0] == '-' && is_number(expression[1])) {
    expression[0] = '~';
    *j = 1;
  }
  if (expression[0] == '+' && is_number(expression[1])) {
    expression[0] = ' ';
  }
  if (length == 1) {
    if (!is_number(expression[0])) {
      error = 3;
    }
  }
  if (length == 3) {
    char *error_str = strstr(expression, "mod");
    if (error_str != NULL) {
      error = 3;
    }
  }
  return error;
}

int check_correct_ending(char *expression, char mass[2], int length) {
  int error = 0;
  if (mass[1] != 0) {
    if (mass[1] == '-') {
      for (int k = length - 1; k > 0; k--) {
        if (expression[k] == '-') {
          expression[k] = '~';
          break;
        }
      }
    } else if (mass[1] == '+') {
      for (int k = length - 1; k > 0; k--) {
        if (expression[k] == '+') {
          expression[k] = ' ';
          break;
        }
      }
    } else if (!is_trig(mass[1])) {
      error = 3;
    }
  }

  return error;
}

int check_number(char *expression, char mass[2], int *sign, int i) {
  int error = 0;
  if (is_number(expression[i]) || expression[i] == '(') {
    if (expression[i] == '(') {
      if (*sign == 2) {
        error = check_mass_is_correct_br(mass);
      }
      if (expression[i + 1] == '-') {
        expression[i + 1] = '~';
      }
      if (expression[i + 1] == '+') {
        expression[i + 1] = ' ';
      }
    }
    *sign = 0;
  }
  return error;
}

void sign_correct_mass(char mass[2], int i, char *expression) {
  if (mass[1] == '-') {
    for (int k = i - 1; k > 0; k--) {
      if (expression[k] == '-') {
        expression[k] = '~';
        break;
      }
    }
  }
  if (mass[1] == '+') {
    for (int k = i - 1; k > 0; k--) {
      if (expression[k] == '+') {
        expression[k] = ' ';
        break;
      }
    }
  }
  for (int l = 0; l < 2; l++) {
    mass[l] = '\0';
  }
}

int sign_sequence(char *expression, int length) {
  int error = 0, count_dot = 0;
  int sign = 0;
  char mass[2] = {0};
  int j = 0;
  error = check_beginning_of_line(expression, length, &j);
  if (!error) {
    for (int i = j; i < length; i++) {
      if (expression[i] == '.') {
        count_dot++;
        if (count_dot > 1) {
          error = 2;
          break;
        }
      }
      error = check_number(expression, mass, &sign, i);
      if (error) {
        break;
      }
      if (is_sign(expression[i])) {
        count_dot = 0;
        if (sign == 2) {
          error = 2;
          break;
        }
        if (sign == 0) {
          sign_correct_mass(mass, i, expression);
        }
        mass[sign] = is_operat(expression[i], expression[i + 1], &i);
        sign++;
      }

      if (check_mass_is_correct(mass)) {
        error = 3;
        break;
      }

      if (i == length - 1) {
        error = check_correct_ending(expression, mass, length);
      }
      if (error) {
        break;
      }
    }
  }
  return error;
}

int check_mass_is_correct(char *mass) {
  int error = 0;
  if (mass[0] == '*' && mass[1] == '*') {
    error = 1;
  }
  if (mass[0] == '/' && mass[1] == '/') {
    error = 1;
  }
  if (mass[0] == '+' && mass[1] == '*') {
    error = 1;
  }
  if (mass[0] == '-' && mass[1] == '*') {
    error = 1;
  }
  if (is_sign(mass[0]) && mass[1] == 'm') {
    error = 1;
  }
  return error;
}

int is_sign(char sign) {
  int error = 0;
  if (sign == '+' || sign == '-') {
    error = 1;
  }
  if (sign == '*' || sign == '/') {
    error = 1;
  }
  if (sign == '^') {
    error = 1;
  }
  if (sign == 'l') {
    error = 1;
  }
  if (sign == 's') {
    error = 1;
  }
  if (sign == 'c') {
    error = 1;
  }
  if (sign == 't') {
    error = 1;
  }
  if (sign == 'a') {
    error = 1;
  }
  if (sign == 'm') {
    error = 1;
  }
  return error;
}

int sign(char sign) {
  int error = 0;
  if (sign == '+' || sign == '-') {
    error = 1;
  }
  if (sign == '*' || sign == '/') {
    error = 1;
  }
  if (sign == '^') {
    error = 1;
  }
  return error;
}

int is_trig(char operat) {
  int error = 0;
  if (operat == 's' || operat == 'c' || operat == 't') {
    error = 1;
  }
  if (operat == 'S' || operat == 'C' || operat == 'T') {
    error = 1;
  }
  if (operat == 'q' || operat == 'L' || operat == 'l') {
    error = 1;
  }
  return error;
}

int staple_sequence(char *expression, int length) {
  int error = 0;
  int is_breaket = 0;
  for (int i = 0; i < length; i++) {
    if (expression[i] == '(') {
      is_breaket++;
    }
    if (expression[i] == '(' && expression[i + 1] == ')') {
      error = 1;
      break;
    }
    if (expression[i] == ')') {
      is_breaket--;
    }
    if (is_breaket < 0) {
      error = 1;
      break;
    }
  }
  if (is_breaket != 0) {
    error = 1;
  }
  return error;
}
int validate_trigonometry(const char *expression, int length) {
  int error = 0;
  char *strp = NULL;
  for (int i = 0; i < length; i++) {
    if (expression[i] == 's') {
      if (expression[i + 1] == 'i') {
        strp = strstr(&expression[i], "sin(");
        if (strp == NULL) {
          error = 2;
          break;
        }
        i += 3;
      } else {
        strp = strstr(&expression[i], "sqrt(");
        if (strp == NULL) {
          error = 2;
          break;
        }
        i += 4;
      }
    }
    if (expression[i] == 'c') {
      strp = strstr(&expression[i], "cos(");
      if (strp == NULL) {
        error = 2;
        break;
      }
      i += 3;
    }
    if (expression[i] == 'l') {
      if (expression[i + 1] == 'n') {
        strp = strstr(&expression[i], "ln(");
        if (strp == NULL) {
          error = 2;
          break;
        }
        i += 2;
      } else {
        strp = strstr(&expression[i], "log(");
        if (strp == NULL) {
          error = 2;
          break;
        }
        i += 3;
      }
    }
    if (expression[i] == 't') {
      strp = strstr(&expression[i], "tan(");
      if (strp == NULL) {
        error = 2;
        break;
      }
      i += 4;
    }
    if (expression[i] == 'a') {
      if (expression[i + 1] == 't') {
        strp = strstr(&expression[i], "atan(");
        if (strp == NULL) {
          error = 1;
          break;
        }
        i += 5;
      }
      if (expression[i + 1] == 's') {
        strp = strstr(&expression[i], "asin(");
        if (strp == NULL) {
          error = 1;
          break;
        }
        i += 5;
      }
      if (expression[i + 1] == 'c') {
        strp = strstr(&expression[i], "acos(");
        if (strp == NULL) {
          error = 2;
          break;
        }
        i += 5;
      }
    }
    if (expression[i] == 'i' || expression[i] == 'E') {
      error = 1;
    }
  }

  return error;
}
