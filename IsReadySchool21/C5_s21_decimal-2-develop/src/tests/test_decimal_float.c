

#include <check.h>
#include <stdio.h>

#include "../s21_decimal.h"
#include "test.h"

#line 1
#include <math.h>
#define assert_float(x, y, z) (fabsl(x - y) < z)

START_TEST(s21_from_decimal_to_float1) {
#line 6

  s21_decimal src1;
  float res, our_res;

  // src1 = 2;

  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  res = 2;

  s21_from_decimal_to_float(src1, &our_res);

  ck_assert_int_eq(assert_float(res, our_res, 1e-6), 1);
}
END_TEST

START_TEST(s21_from_decimal_to_float2) {
#line 24

  s21_decimal src1;
  float res, our_res;

  // src1 = -2;

  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;

  res = -2;

  s21_from_decimal_to_float(src1, &our_res);

  ck_assert_int_eq(assert_float(res, our_res, 1e-6), 1);
}
END_TEST

START_TEST(s21_from_decimal_to_float3) {
#line 42

  s21_decimal src1;
  float res, our_res;

  // src1 = 2;

  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  res = 2;

  s21_from_decimal_to_float(src1, &our_res);

  ck_assert_int_eq(assert_float(res, our_res, 1e-6), 1);
}
END_TEST

START_TEST(s21_from_decimal_to_float4) {
#line 60

  s21_decimal src1;
  float res, our_res;

  // src1 = -2;

  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;

  res = -2;

  s21_from_decimal_to_float(src1, &our_res);

  ck_assert_int_eq(assert_float(res, our_res, 1e-6), 1);
}
END_TEST

START_TEST(s21_from_decimal_to_float5) {
#line 78

  s21_decimal src1;
  float res, our_res;

  // src1 = 3;

  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  res = 3;

  s21_from_decimal_to_float(src1, &our_res);

  ck_assert_int_eq(assert_float(res, our_res, 1e-6), 1);
}
END_TEST

START_TEST(s21_from_decimal_to_float6) {
#line 96

  s21_decimal src1;
  float res, our_res;

  // src1 = -3;

  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;

  res = -3;

  s21_from_decimal_to_float(src1, &our_res);

  ck_assert_int_eq(assert_float(res, our_res, 1e-6), 1);
}
END_TEST

START_TEST(s21_from_decimal_to_float7) {
#line 114

  s21_decimal src1;
  float res, our_res;

  // src1 = 3;

  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  res = 3;

  s21_from_decimal_to_float(src1, &our_res);

  ck_assert_int_eq(assert_float(res, our_res, 1e-6), 1);
}
END_TEST

START_TEST(s21_from_decimal_to_float8) {
#line 132

  s21_decimal src1;
  float res, our_res;

  // src1 = -3;

  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;

  res = -3;

  s21_from_decimal_to_float(src1, &our_res);

  ck_assert_int_eq(assert_float(res, our_res, 1e-6), 1);
}
END_TEST

START_TEST(s21_from_decimal_to_float9) {
#line 150

  s21_decimal src1;
  float res, our_res;

  // src1 = 3;

  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  res = 3;

  s21_from_decimal_to_float(src1, &our_res);

  ck_assert_int_eq(assert_float(res, our_res, 1e-6), 1);
}
END_TEST

START_TEST(s21_from_decimal_to_float10) {
#line 168

  s21_decimal src1;
  float res, our_res;

  // src1 = -3;

  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;

  res = -3;

  s21_from_decimal_to_float(src1, &our_res);

  ck_assert_int_eq(assert_float(res, our_res, 1e-6), 1);
}
END_TEST

START_TEST(s21_from_decimal_to_float11) {
#line 186

  s21_decimal src1;
  float res, our_res;

  // src1 = 3;

  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  res = 3;

  s21_from_decimal_to_float(src1, &our_res);

  ck_assert_int_eq(assert_float(res, our_res, 1e-6), 1);
}
END_TEST

START_TEST(s21_from_decimal_to_float12) {
#line 204

  s21_decimal src1;
  float res, our_res;

  // src1 = -3;

  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;

  res = -3;

  s21_from_decimal_to_float(src1, &our_res);

  ck_assert_int_eq(assert_float(res, our_res, 1e-6), 1);
}
END_TEST

START_TEST(s21_from_decimal_to_float13) {
#line 222

  s21_decimal src1;
  float res, our_res;

  // src1 = 0;

  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  res = 0;

  s21_from_decimal_to_float(src1, &our_res);

  ck_assert_int_eq(assert_float(res, our_res, 1e-6), 1);
}
END_TEST

START_TEST(s21_from_decimal_to_float14) {
#line 240

  s21_decimal src1;
  float res, our_res;

  // src1 = 0;

  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  res = 0;

  s21_from_decimal_to_float(src1, &our_res);

  ck_assert_int_eq(assert_float(res, our_res, 1e-6), 1);
}
END_TEST

START_TEST(s21_from_decimal_to_float15) {
#line 258

  s21_decimal src1;
  float res, our_res;

  // src1 = 3.2;

  src1.bits[0] = 0b00000000000000000000000000100000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;

  res = 3.2;

  s21_from_decimal_to_float(src1, &our_res);

  ck_assert_int_eq(assert_float(res, our_res, 1e-6), 1);
}
END_TEST

START_TEST(s21_from_decimal_to_float16) {
#line 276

  s21_decimal src1;
  float res, our_res;

  // src1 = -3.2;

  src1.bits[0] = 0b00000000000000000000000000100000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000010000000000000000;

  res = -3.2;

  s21_from_decimal_to_float(src1, &our_res);

  ck_assert_int_eq(assert_float(res, our_res, 1e-6), 1);
}
END_TEST

START_TEST(s21_from_decimal_to_float17) {
#line 294

  s21_decimal src1;
  float res, our_res;

  // src1 = -3.2;

  src1.bits[0] = 0b00000000000000000000000000100000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000010000000000000000;

  res = -3.2;

  s21_from_decimal_to_float(src1, &our_res);

  ck_assert_int_eq(assert_float(res, our_res, 1e-6), 1);
}
END_TEST

START_TEST(s21_from_decimal_to_float18) {
#line 312

  s21_decimal src1;
  float res, our_res;

  // src1 = 3.2;

  src1.bits[0] = 0b00000000000000000000000000100000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;

  res = 3.2;

  s21_from_decimal_to_float(src1, &our_res);

  ck_assert_int_eq(assert_float(res, our_res, 1e-6), 1);
}
END_TEST

START_TEST(s21_from_decimal_to_float19) {
#line 330

  s21_decimal src1;
  float res, our_res;

  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b00000000000101010000000000000000;

  res = 1.2345678E+07;

  s21_from_decimal_to_float(src1, &our_res);

  ck_assert_int_eq(assert_float(res, our_res, 1e-6), 1);
}
END_TEST

START_TEST(s21_from_decimal_to_float20) {
#line 348

  s21_decimal src1;
  float res, our_res;

  // src1 = -12345677.987654345678987654346;

  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b10000000000101010000000000000000;

  res = -1.2345678E+07;

  s21_from_decimal_to_float(src1, &our_res);

  ck_assert_int_eq(assert_float(res, our_res, 1e-6), 1);
}
END_TEST

START_TEST(s21_from_decimal_to_float21) {
#line 366

  s21_decimal src1;
  float res, our_res;

  // src1 = 12345677.987654345678987654346;

  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b00000000000101010000000000000000;

  res = 1.2345678E+07;

  s21_from_decimal_to_float(src1, &our_res);

  ck_assert_int_eq(assert_float(res, our_res, 1e-6), 1);
}
END_TEST

START_TEST(s21_from_decimal_to_float22) {
#line 384

  s21_decimal src1;
  float res, our_res;

  // src1 = -12345677.987654345678987654346;

  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b10000000000101010000000000000000;

  res = -1.2345678E+07;

  s21_from_decimal_to_float(src1, &our_res);

  ck_assert_int_eq(assert_float(res, our_res, 1e-6), 1);
}
END_TEST

START_TEST(s21_from_decimal_to_float28) {
#line 492

  s21_decimal src1;
  float res, our_res;

  // src1 = 665464545;

  src1.bits[0] = 0b00100111101010100010111011100001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  res = 6.654646E+08;

  s21_from_decimal_to_float(src1, &our_res);

  ck_assert_int_eq(assert_float(res, our_res, 1e-6), 1);
}
END_TEST

START_TEST(s21_from_decimal_to_float29) {
#line 510

  s21_decimal src1;
  float res, our_res;

  // src1 = 2.7986531268974139743;

  src1.bits[0] = 0b11111110100100001101100101011111;
  src1.bits[1] = 0b10000100011001000010000111101000;
  src1.bits[2] = 0b00000000000000000000000000000001;
  src1.bits[3] = 0b00000000000100110000000000000000;

  res = 2.798653;

  s21_from_decimal_to_float(src1, &our_res);

  ck_assert_int_eq(assert_float(res, our_res, 1e-6), 1);
}
END_TEST

START_TEST(s21_from_decimal_to_float30) {
#line 528

  s21_decimal src1;
  float res, our_res;

  // src1 = -9798956154578676.797564534156;

  src1.bits[0] = 0b01010100010000000011110110001100;
  src1.bits[1] = 0b10001011010100100000010101011001;
  src1.bits[2] = 0b00011111101010011000000110101101;
  src1.bits[3] = 0b10000000000011000000000000000000;

  res = -9.798956E+15;

  s21_from_decimal_to_float(src1, &our_res);

  ck_assert_int_eq(assert_float(res, our_res, 1e-6), 1);
}
END_TEST

START_TEST(s21_from_decimal_to_float31) {
#line 546

  s21_decimal src1;
  float res, our_res;

  // src1 = 0.5456465465486476846545465485;

  src1.bits[0] = 0b00001011000011110111000010001101;
  src1.bits[1] = 0b10010110101100000101100101010001;
  src1.bits[2] = 0b00010001101000010111101110000001;
  src1.bits[3] = 0b00000000000111000000000000000000;

  res = 0.5456465;

  s21_from_decimal_to_float(src1, &our_res);

  ck_assert_int_eq(assert_float(res, our_res, 1e-6), 1);
}
END_TEST

START_TEST(s21_from_decimal_to_float32) {
#line 564

  s21_decimal src1;
  float res, our_res;

  // src1 = -0.77545545454546589781;

  src1.bits[0] = 0b10101100001010000001100001010101;
  src1.bits[1] = 0b00110100001010010001111010111100;
  src1.bits[2] = 0b00000000000000000000000000000100;
  src1.bits[3] = 0b10000000000101000000000000000000;

  res = -0.7754555;

  s21_from_decimal_to_float(src1, &our_res);

  ck_assert_int_eq(assert_float(res, our_res, 1e-6), 1);
}
END_TEST

START_TEST(s21_from_decimal_to_float36) {
#line 636

  s21_decimal src1;
  float res, our_res;

  // src1 = 0;

  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  res = 0;

  s21_from_decimal_to_float(src1, &our_res);

  ck_assert_int_eq(assert_float(res, our_res, 1e-6), 1);
}
END_TEST

START_TEST(s21_from_decimal_to_float37) {
#line 654

  s21_decimal src1;
  float res, our_res;

  // src1 = 1.0;

  src1.bits[0] = 0b00000000000000000000000000001010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;

  res = 1;

  s21_from_decimal_to_float(src1, &our_res);

  ck_assert_int_eq(assert_float(res, our_res, 1e-6), 1);
}
END_TEST

START_TEST(s21_from_decimal_to_float38) {
#line 672

  s21_decimal src1;
  float res, our_res;

  // src1 = -1.0;

  src1.bits[0] = 0b00000000000000000000000000001010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000010000000000000000;

  res = -1;

  s21_from_decimal_to_float(src1, &our_res);

  ck_assert_int_eq(assert_float(res, our_res, 1e-6), 1);
}
END_TEST

START_TEST(s21_from_decimal_to_float39) {
#line 690

  s21_decimal src1;
  float res, our_res;

  // src1 = 1.0;

  src1.bits[0] = 0b00000000000000000000000000001010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;

  res = 1;

  s21_from_decimal_to_float(src1, &our_res);

  ck_assert_int_eq(assert_float(res, our_res, 1e-6), 1);
}
END_TEST

START_TEST(s21_from_decimal_to_float40) {
#line 708

  s21_decimal src1;
  float res, our_res;

  // src1 = -1.0;

  src1.bits[0] = 0b00000000000000000000000000001010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000010000000000000000;

  res = -1;

  s21_from_decimal_to_float(src1, &our_res);

  ck_assert_int_eq(assert_float(res, our_res, 1e-6), 1);
}
END_TEST

START_TEST(s21_from_decimal_to_float43) {
#line 762

  s21_decimal src1;
  float res, our_res;

  // src1 = 792281625142643375935439503;

  src1.bits[0] = 0b00101000111101011100001010001111;
  src1.bits[1] = 0b11110101110000101000111101011100;
  src1.bits[2] = 0b00000010100011110101110000101000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  res = 7.922816E+26;

  s21_from_decimal_to_float(src1, &our_res);

  ck_assert_int_eq(assert_float(res, our_res, 1e-6), 1);
}
END_TEST

START_TEST(s21_from_decimal_to_float45) {
#line 798

  s21_decimal src1;
  float res, our_res;

  // src1 = 0.0000000000000000000002;

  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000101100000000000000000;

  res = 2E-22;

  s21_from_decimal_to_float(src1, &our_res);

  ck_assert_int_eq(assert_float(res, our_res, 1e-6), 1);
}
END_TEST

START_TEST(s21_from_decimal_to_float46) {
#line 816

  s21_decimal src1;
  float res, our_res;

  // src1 = -0.0000000000000000000002;

  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000101100000000000000000;

  res = -2E-22;

  s21_from_decimal_to_float(src1, &our_res);
  ck_assert_int_eq(assert_float(res, our_res, 1e-6), 1);
}
END_TEST

START_TEST(s21_from_decimal_to_float47) {
#line 834

  s21_decimal src1;
  float res, our_res;

  // src1 = 0.0000000000000000000002;

  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000101100000000000000000;

  res = 2E-22;

  s21_from_decimal_to_float(src1, &our_res);

  ck_assert_int_eq(assert_float(res, our_res, 1e-6), 1);
}
END_TEST

START_TEST(s21_from_decimal_to_float48) {
#line 852

  s21_decimal src1;
  float res, our_res;

  // src1 = 0.0000000000000000000002;

  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000101100000000000000000;

  res = 2E-22;

  s21_from_decimal_to_float(src1, &our_res);

  ck_assert_int_eq(assert_float(res, our_res, 1e-6), 1);
}
END_TEST

Suite *s21_s21_from_decimal_to_float(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, s21_from_decimal_to_float1);
  tcase_add_test(tc1_1, s21_from_decimal_to_float2);
  tcase_add_test(tc1_1, s21_from_decimal_to_float3);
  tcase_add_test(tc1_1, s21_from_decimal_to_float4);
  tcase_add_test(tc1_1, s21_from_decimal_to_float5);
  tcase_add_test(tc1_1, s21_from_decimal_to_float6);
  tcase_add_test(tc1_1, s21_from_decimal_to_float7);
  tcase_add_test(tc1_1, s21_from_decimal_to_float8);
  tcase_add_test(tc1_1, s21_from_decimal_to_float9);
  tcase_add_test(tc1_1, s21_from_decimal_to_float10);
  tcase_add_test(tc1_1, s21_from_decimal_to_float11);
  tcase_add_test(tc1_1, s21_from_decimal_to_float12);
  tcase_add_test(tc1_1, s21_from_decimal_to_float13);
  tcase_add_test(tc1_1, s21_from_decimal_to_float14);
  tcase_add_test(tc1_1, s21_from_decimal_to_float15);
  tcase_add_test(tc1_1, s21_from_decimal_to_float16);
  tcase_add_test(tc1_1, s21_from_decimal_to_float17);
  tcase_add_test(tc1_1, s21_from_decimal_to_float18);
  tcase_add_test(tc1_1, s21_from_decimal_to_float19);
  tcase_add_test(tc1_1, s21_from_decimal_to_float20);
  tcase_add_test(tc1_1, s21_from_decimal_to_float21);
  tcase_add_test(tc1_1, s21_from_decimal_to_float22);
  tcase_add_test(tc1_1, s21_from_decimal_to_float28);
  tcase_add_test(tc1_1, s21_from_decimal_to_float29);
  tcase_add_test(tc1_1, s21_from_decimal_to_float30);
  tcase_add_test(tc1_1, s21_from_decimal_to_float31);
  tcase_add_test(tc1_1, s21_from_decimal_to_float32);
  tcase_add_test(tc1_1, s21_from_decimal_to_float36);
  tcase_add_test(tc1_1, s21_from_decimal_to_float37);
  tcase_add_test(tc1_1, s21_from_decimal_to_float38);
  tcase_add_test(tc1_1, s21_from_decimal_to_float39);
  tcase_add_test(tc1_1, s21_from_decimal_to_float40);
  tcase_add_test(tc1_1, s21_from_decimal_to_float43);
  tcase_add_test(tc1_1, s21_from_decimal_to_float45);
  tcase_add_test(tc1_1, s21_from_decimal_to_float46);
  tcase_add_test(tc1_1, s21_from_decimal_to_float47);
  tcase_add_test(tc1_1, s21_from_decimal_to_float48);

  return s1;
}
