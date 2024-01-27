#include <stdio.h>
#include <stdlib.h>

#include "s21_decimal.h"

int get_bit(unsigned int bite, int pos) {
  int result = 0;
  if (1U & bite >> pos) {
    result = 1;
  }

  return result;
}

void set_bit(unsigned int *res, int placeBit) {
  int x = 1;
  x <<= placeBit;
  *res |= x;
}

int get_bit_mantisa(s21_decimal x, int getbit) {
  int res = 0;
  if (getbit >= 0 && getbit <= 31) {
    res = get_bit(x.bits[0], getbit);
  }
  if (getbit >= 32 && getbit <= 63) {
    res = get_bit(x.bits[1], getbit - 32);
  }
  if (getbit >= 64 && getbit <= 95) {
    res = get_bit(x.bits[2], getbit - 64);
  }
  return res;
}

void shift_left(s21_decimal *first, int shift) {
  for (int i = 0; i < shift; i++) {
    int f1 = (first->bits[0] & LEFT_BIT) == LEFT_BIT;
    int f2 = (first->bits[1] & LEFT_BIT) == LEFT_BIT;

    first->bits[0] <<= 1;
    first->bits[1] <<= 1;
    first->bits[2] <<= 1;

    if (f1) {
      set_bit(&first->bits[1], 0);
    }
    if (f2) {
      set_bit(&first->bits[2], 0);
    }
  }
}

void mul10(s21_decimal *value_1) {
  s21_decimal result = {0};
  comm_byte a;
  a.bits = value_1->bits[3];
  int mul = 10;
  while (mul != 0) {
    if ((mul & RIGHT_BIT) == RIGHT_BIT) {
      s21_add(*value_1, result, &result);
    }
    mul >>= 1;
    shift_left(value_1, 1);
  }
  value_1->bits[0] = result.bits[0];
  value_1->bits[1] = result.bits[1];
  value_1->bits[2] = result.bits[2];
  value_1->bits[3] = a.bits;
}

int is_decimal_zero(s21_decimal value) {
  int flag = 1;
  for (int i = 0; i < 3; i++)
    if (value.bits[i] != 0) {
      flag = 0;
    }

  return flag;
}

void decimal_to_null(s21_decimal *value) {
  for (int i = 0; i < 4; i++) {
    value->bits[i] = 0;
  }
}

void align_exp(s21_decimal *value_1, s21_decimal *value_2) {
  int exp = 0;
  comm_byte vl_1, vl_2;

  vl_1.bits = value_1->bits[3];
  vl_2.bits = value_2->bits[3];

  if (vl_1.bite.exp > vl_2.bite.exp) {
    exp = vl_1.bite.exp - vl_2.bite.exp;
    for (int i = 0; i < exp; i++) {
      mul10(value_2);
    }
    vl_2.bite.exp = vl_1.bite.exp;
    value_2->bits[3] = vl_2.bits;
  }
  if (vl_1.bite.exp < vl_2.bite.exp) {
    exp = vl_2.bite.exp - vl_1.bite.exp;
    for (int i = 0; i < exp; i++) {
      mul10(value_1);
    }
    vl_1.bite.exp = vl_2.bite.exp;
    value_1->bits[3] = vl_1.bits;
  }
}

int length_int(int bits) {
  int length = 1;
  if (bits < 0) {
    bits = -bits;
  }

  while (bits > 9) {
    bits /= 10;
    length++;
  }

  return length;
}