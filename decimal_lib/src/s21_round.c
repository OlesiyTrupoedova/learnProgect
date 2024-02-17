#include <stdio.h>

#include "s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
  decimal_to_null(result);
  comm_byte v = {0};
  v.bits = value.bits[3];

  s21_decimal old_value = {0};
  for (int i = 0; i < 4; i++) {
    old_value.bits[i] = value.bits[i];
  }

  s21_truncate(value, &value);

  if (v.bite.unar && s21_is_not_equal(old_value, value)) {
    s21_decimal temp = {0};
    temp.bits[0] = 1;

    s21_sub(value, temp, result);
  } else
    *result = value;

  return 0;
}

int s21_round(s21_decimal value, s21_decimal *result) {
  decimal_to_null(result);
  big_decimal temp = {0}, big_value = {0}, big_result = {0};
  comm_byte v = {0}, t = {0};

  v.bits = value.bits[3];

  t.bits = value.bits[3];

  to_big_decimal(value, &big_value);
  big_value.bits[6] = 0;

  t.bite.exp = 0;

  temp.bits[0] = 10;
  int rest = 0;
  for (int i = 0; i < v.bite.exp; i++) {
    div_completely(&big_value, temp, &big_result);
    rest = big_value.bits[0];
    for (int j = 0; j < 6; j++) {
      big_value.bits[j] = big_result.bits[j];
    }
  }

  if (rest >= 5) {
    temp.bits[0] = 1;
    add_big_decimal(big_value, temp, &big_value);
  }

  from_big_decimal(big_value, result);
  result->bits[3] = t.bits;

  return 0;
}

int s21_truncate(s21_decimal value, s21_decimal *result) {
  decimal_to_null(result);
  big_decimal temp = {0}, big_value = {0}, big_result = {0};
  comm_byte v = {0}, t = {0};

  v.bits = value.bits[3];
  t.bits = value.bits[3];

  to_big_decimal(value, &big_value);
  big_value.bits[6] = 0;

  t.bite.exp = 0;

  temp.bits[0] = 10;
  for (int i = 0; i < v.bite.exp; i++) {
    div_completely(&big_value, temp, &big_result);
    for (int j = 0; j < 6; j++) {
      big_value.bits[j] = big_result.bits[j];
    }
  }
  from_big_decimal(big_value, result);

  result->bits[3] = t.bits;

  return 0;
}

int s21_negate(s21_decimal value, s21_decimal *result) {
  decimal_to_null(result);

  comm_byte res = {0};

  *result = value;

  res.bits = result->bits[3];
  res.bite.unar = res.bite.unar ? 0 : 1;
  result->bits[3] = res.bits;

  return 0;
}
