#include <stdio.h>

#include "s21_decimal.h"

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  decimal_to_null(result);
  int error = 0;

  if (!is_decimal_zero(value_2) && !is_decimal_zero(value_1)) {
    big_decimal big_value_1 = {0}, big_value_2 = {0}, big_result = {0};

    to_big_decimal(value_1, &big_value_1);
    to_big_decimal(value_2, &big_value_2);

    comm_byte v1, v2, res = {0};

    v1.bits = value_1.bits[3];
    v2.bits = value_2.bits[3];

    res.bite.unar = v1.bite.unar ^ v2.bite.unar;

    v1.bite.unar = 0;
    v2.bite.unar = 0;

    big_value_1.bits[6] = v1.bits;
    big_value_2.bits[6] = v2.bits;

    res.bite.exp = v1.bite.exp + v2.bite.exp;

    while (!is_big_decimal_zero(big_value_2)) {
      if ((big_value_2.bits[0] & RIGHT_BIT) == RIGHT_BIT) {
        add_big_decimal(big_value_1, big_result, &big_result);
      }

      shift_right_for_big(&big_value_2, 1);
      shift_left_for_big(&big_value_1, 1);
    }

    big_result.bits[6] = res.bits;

    error = from_big_decimal(big_result, result);
  }

  return error;
}

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int error = 0;

  decimal_to_null(result);

  if (is_decimal_zero(value_2))
    error = 3;
  else if (is_decimal_zero(value_1)) {
    comm_byte v2 = {0}, res = {0};

    v2.bits = value_2.bits[3];
    if (v2.bite.unar) {
      res.bite.unar = 1;
      result->bits[3] = res.bits;
    }
  } else {
    big_decimal big_value_1 = {0}, big_value_2 = {0}, big_result = {0};

    to_big_decimal(value_1, &big_value_1);
    to_big_decimal(value_2, &big_value_2);

    comm_byte v1, v2, res = {0};

    big_align_exp(&big_value_1, &big_value_2);

    v1.bits = value_1.bits[3];
    v2.bits = value_2.bits[3];

    res.bite.unar = v1.bite.unar ^ v2.bite.unar;

    int exp1 = v1.bite.exp;
    int exp2 = v2.bite.exp;
    v1.bite.exp = 0;
    v2.bite.exp = 0;
    v1.bite.unar = 0;
    v2.bite.unar = 0;

    big_value_1.bits[6] = v1.bits;
    big_value_2.bits[6] = v2.bits;

    div_completely(&big_value_1, big_value_2, &big_result);

    if (is_big_equal_with_int(big_value_1, 0)) {
      res.bite.exp = exp1 - exp2;
    }

    big_decimal temp_res = {0};

    while (!is_big_equal_with_int(big_value_1, 0)) {
      int count_exp = 0;
      while (is_less_for_big(big_value_1, big_value_2)) {
        mul10_for_big(&big_value_1);
        if (count_exp > 0) {
          res.bite.exp += 1;
          mul10_for_big(&big_result);
        }
        count_exp++;
      }

      decimal_to_null_for_big(&temp_res);
      div_completely(&big_value_1, big_value_2, &temp_res);

      for (int i = 0; i < length_big_decimal(temp_res); i++)
        mul10_for_big(&big_result);

      add_big_decimal(big_result, temp_res, &big_result);
      res.bite.exp += length_big_decimal(temp_res);

      if (big_result.bits[5] != 0) {
        break;
      }
    }

    big_result.bits[6] = res.bits;

    error = from_big_decimal(big_result, result);
  }

  return error;
}