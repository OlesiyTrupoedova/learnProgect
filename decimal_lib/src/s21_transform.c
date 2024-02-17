#include <limits.h>
#include <stdio.h>
#include <string.h>

#include "s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int error = 0;
  long long int ds = 0;
  comm_byte byte;
  byte.bits = src.bits[3];
  if (byte.bite.exp) {
    s21_truncate(src, &src);
  }
  for (int i = 1; i < 3; i++) {
    if (src.bits[i] != 0 && !byte.bite.unar) {
      error = 1;
      break;
    }
  }
  ds = (long long int)src.bits[0];
  if (byte.bite.unar) {
    ds *= -1;
  }
  if (ds > INT_MAX || ds < INT_MIN) {
    error = 1;
    *dst = INT_MAX;
  } else {
    *dst = ds;
  }

  return error;
}

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int error = 0;
  for (int i = 0; i < 4; i++) {
    dst->bits[i] = 0;
  }
  comm_byte b;
  b.bits = dst->bits[3];
  if (src < 0) {
    src *= -1;
    b.bite.unar = 1;
  }
  dst->bits[0] = src;
  dst->bits[3] = b.bits;
  return error;
}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  comm_byte byte;
  double res = 0;
  byte.bits = src.bits[3];
  for (int i = 0; i < 96; i++) {
    if (get_bit_mantisa(src, i)) {
      res += pow(2, i);
    }
  }
  res *= pow(10, -byte.bite.exp);
  if (byte.bite.unar) {
    res *= -1;
  }

  *dst = res;
  return 0;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  decimal_to_null(dst);
  int exp = 0, g = 0, wt = 0;
  comm_byte byte = {0};
  byte.bits = 0;
  if (src < 0) {
    byte.bite.unar = 1;
    src *= -1;
  }

  char mass[15] = {0};
  char res[14] = {0};
  sprintf(mass, "%.6e", src);
  for (int i = 0; i < 14; i++) {
    if (mass[i] == 'e') {
      break;
    }
    if (mass[i] == '.') {
      continue;
    }
    res[g] = mass[i];
    g++;
  }

  for (int i = 10; i < 13; i++) {
    if (mass[i] >= '0' && mass[i] <= '9') {
      exp *= 10;
      exp += mass[i] - '0';
    }
  }
  if (mass[9] == '+') {
    // exp += 1;
    for (int i = 0; i <= 6; i++) {
      wt *= 10;
      wt += res[i] - '0';
      if (i == 0) {
        continue;
      }
      if (exp <= 0) {
        byte.bite.exp++;
      }
      exp--;
    }
    dst->bits[0] = wt;
    for (; exp > 0; exp--) {
      mul10(dst);
    }
  }
  if (mass[9] == '-') {
    for (int i = 0; i <= 6; i++) {
      wt *= 10;
      wt += res[i] - '0';
    }
    dst->bits[0] = wt;
    byte.bite.exp = -exp - 6;
    byte.bite.exp *= -1;
  }
  dst->bits[3] = byte.bits;
  return 0;
}
