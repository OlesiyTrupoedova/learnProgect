#include <stdio.h>

#include "s21_decimal.h"
int s21_is_not_equal(s21_decimal first, s21_decimal second) {
  return !s21_is_equal(first, second);
}

int s21_is_equal(s21_decimal first, s21_decimal second) {
  int is_equal = 1;

  align_exp(&first, &second);

  for (int i = 0; i < 4 && is_equal; i++) {
    if (first.bits[i] != second.bits[i]) {
      is_equal = 0;
    }
  }
  return is_equal;
}

int s21_is_greater(s21_decimal first, s21_decimal second) {
  big_decimal big_first = {0}, big_second = {0};
  comm_byte bn1, bn2;

  bn1.bits = first.bits[3];
  bn2.bits = second.bits[3];

  int result = 0;

  to_big_decimal(first, &big_first);
  to_big_decimal(second, &big_second);

  big_align_exp(&big_first, &big_second);

  if (bn1.bite.unar && bn2.bite.unar) {
    if (first_set_bit_for_big(big_first) < first_set_bit_for_big(big_second))
      result = 1;
    else if (first_set_bit_for_big(big_first) ==
             first_set_bit_for_big(big_second)) {
      for (int i = first_set_bit_for_big(big_first); i >= 0; i--) {
        if (!get_bit_mantisa_for_big(big_first, i) &&
            get_bit_mantisa_for_big(big_second, i)) {
          result = 1;
          break;
        } else if (get_bit_mantisa_for_big(big_first, i) &&
                   !get_bit_mantisa_for_big(big_second, i))
          break;
      }
    }
  } else if (bn1.bite.unar || bn2.bite.unar) {
    if (bn2.bite.unar) {
      result = 1;
    }
  } else {
    if (first_set_bit_for_big(big_first) > first_set_bit_for_big(big_second)) {
      result = 1;
    } else if (first_set_bit_for_big(big_first) ==
               first_set_bit_for_big(big_second)) {
      for (int i = first_set_bit_for_big(big_first); i >= 0; i--) {
        if (get_bit_mantisa_for_big(big_first, i) &&
            !get_bit_mantisa_for_big(big_second, i)) {
          result = 1;
          break;
        } else if (!get_bit_mantisa_for_big(big_first, i) &&
                   get_bit_mantisa_for_big(big_second, i))
          break;
      }
    }
  }

  return result;
}

int s21_is_greater_or_equal(s21_decimal first, s21_decimal second) {
  return s21_is_greater(first, second) || s21_is_equal(first, second);
}

int s21_is_less_or_equal(s21_decimal first, s21_decimal second) {
  return !s21_is_greater(first, second);
}

int s21_is_less(s21_decimal first, s21_decimal second) {
  return !s21_is_greater_or_equal(first, second);
}
