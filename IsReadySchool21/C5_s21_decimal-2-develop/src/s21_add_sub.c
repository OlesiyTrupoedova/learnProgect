#include <stdio.h>

#include "s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  decimal_to_null(result);

  big_decimal big_value_1 = {0}, big_value_2 = {0}, big_result = {0};
  comm_byte res, big_res;

  int error = 0;

  to_big_decimal(value_1, &big_value_1);
  to_big_decimal(value_2, &big_value_2);

  big_align_exp(&big_value_1, &big_value_2);

  res.bits = big_value_1.bits[6];

  add_big_decimal(big_value_1, big_value_2, &big_result);

  big_res.bits = big_result.bits[6];
  big_res.bite.exp = res.bite.exp;
  big_result.bits[6] = big_res.bits;

  error = from_big_decimal(big_result, result);
  return error;
}

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  big_decimal big_value_1 = {0}, big_value_2 = {0}, big_result = {0};
  comm_byte res, big_res;

  int error = 0;

  to_big_decimal(value_1, &big_value_1);
  to_big_decimal(value_2, &big_value_2);

  big_align_exp(&big_value_1, &big_value_2);

  res.bits = big_value_1.bits[6];

  sub_big_decimal(big_value_1, big_value_2, &big_result);

  big_res.bits = big_result.bits[6];
  big_res.bite.exp = res.bite.exp;
  big_result.bits[6] = big_res.bits;

  error = from_big_decimal(big_result, result);

  return error;
}
