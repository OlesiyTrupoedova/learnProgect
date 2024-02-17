#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "logic.h"

char *polish_notation(const char *expression) {
  int j = 0;
  int length = strlen(expression);
  in_stack stack;
  stack.len = 0;
  char *result = malloc(255 * sizeof(char));
  for (int i = 0; i < 255; i++) {
    stack.expression[i].operat = '\0';
  }
  for (int i = 0; i < 255; i++) {
    result[i] = '\0';
  }

  for (int i = 0; i < length; i++) {
    if (expression[i] == ' ') {
      continue;
    }
    if (is_number(expression[i])) {
      number_in_result(result, expression, &j, &i);
      result[j] = ' ';
      j++;
    } else {
      if (expression[i] == ')') {
        get_out_stack_breakets(&stack, result, &j);
      } else {
        put_in_stack(&stack, expression[i], expression[i + 1], &i);
        get_out_stack(&stack, result, &j);
      }
    }
  }
  while (stack.len != 0) {
    result[j] = stack.expression[stack.len - 1].operat;
    stack.len--;
    j++;
  }
  result[j] = '\0';
  return result;
}

void number_in_result(char *result, const char *expression, int *j, int *i) {
  for (; is_number(expression[*i]); *i += 1) {
    result[*j] = expression[*i];
    *j += 1;
  }
  *i -= 1;
}

void put_in_stack(in_stack *stack, char operat, char op, int *i) {
  stack->expression[stack->len].operat = is_operat(operat, op, i);
  stack->expression[stack->len].priority =
      is_priority(stack->expression[stack->len].operat);
  stack->len++;
}

void get_out_stack(in_stack *stack, char *result, int *j) {
  if (stack->len > 1) {
    int priority_operat = stack->expression[stack->len - 1].priority;
    int priority_operat2 = stack->expression[stack->len - 2].priority;
    if (priority_operat == 5) {
      while (priority_operat < priority_operat2) {
        if (priority_operat == 0 || priority_operat2 == 0) {
          break;
        }
        result[*j] = stack->expression[stack->len - 2].operat;
        *j += 1;
        result[*j] = ' ';
        *j += 1;
        stack->expression[stack->len - 2].operat =
            stack->expression[stack->len - 1].operat;
        stack->expression[stack->len - 2].priority =
            stack->expression[stack->len - 1].priority;
        stack->len--;
        if (stack->len == 1) {
          break;
        }
        priority_operat = stack->expression[stack->len - 1].priority;
        priority_operat2 = stack->expression[stack->len - 2].priority;
      }
    } else {
      while (priority_operat <= priority_operat2) {
        if (priority_operat == 0 || priority_operat2 == 0) {
          break;
        }
        result[*j] = stack->expression[stack->len - 2].operat;
        *j += 1;
        result[*j] = ' ';
        *j += 1;
        stack->expression[stack->len - 2].operat =
            stack->expression[stack->len - 1].operat;
        stack->expression[stack->len - 2].priority =
            stack->expression[stack->len - 1].priority;
        stack->len--;
        if (stack->len == 1) {
          break;
        }
        priority_operat = stack->expression[stack->len - 1].priority;
        priority_operat2 = stack->expression[stack->len - 2].priority;
      }
    }
  }
}

void get_out_stack_breakets(in_stack *stack, char *result, int *j) {
  while (1) {
    if (stack->expression[stack->len - 1].operat == '(') {
      stack->len--;
      break;
    }
    result[*j] = stack->expression[stack->len - 1].operat;
    *j += 1;
    result[*j] = ' ';
    *j += 1;

    stack->len--;
  }
  get_out_stack(stack, result, j);
}

char is_operat(char operat, char op, int *i) {
  char result = '\0';
  if (operat == '+' || operat == '-') {
    result = operat;
  }
  if (operat == '*' || operat == '/') {
    result = operat;
  }
  if (operat == '^') {
    result = operat;
  }
  if (operat == '~') {
    result = operat;
  }
  if (operat == 'l') {
    if (op == 'n') {
      result = operat;
      *i += 1;
    } else {
      result = 'L';
      *i += 2;
    }
  }
  if (operat == 's') {
    if (op == 'q') {
      result = 'q';
      *i += 3;
    } else {
      result = operat;
      *i += 2;
    }
  }
  if (operat == 'c') {
    result = operat;
    *i += 2;
  }
  if (operat == 't') {
    result = operat;
    *i += 2;
  }
  if (operat == 'a') {
    if (op == 's') {
      result = 'S';
      *i += 3;
    }
    if (op == 'c') {
      result = 'C';
      *i += 3;
    }
    if (op == 't') {
      result = 'T';
      *i += 3;
    }
  }
  if (operat == 'm') {
    result = operat;
    *i += 2;
  }
  if (operat == '(') {
    result = operat;
  }
  return result;
}

int is_priority(char operat) {
  int priority = 0;
  if (operat == '+' || operat == '-') {
    priority = 2;
  }
  if (operat == '*' || operat == '/' || operat == 'm') {
    priority = 3;
  }
  if (operat == '^') {
    priority = 5;
  }
  if (operat == '~') {
    priority = 5;
  }
  if (operat == 's' || operat == 'c' || operat == 't') {
    priority = 6;
  }
  if (operat == 'S' || operat == 'C' || operat == 'T') {
    priority = 6;
  }
  if (operat == 'q' || operat == 'L') {
    priority = 6;
  }
  if (operat == '(') {
    priority = 0;
  }
  return priority;
}
