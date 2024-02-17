#include <check.h>
#include <stdio.h>

#include "../s21_decimal.h"
#include "test.h"

#line 1
START_TEST(s21_s21_is_mul41) {
#line 2

  s21_decimal src1, src2, res, our_res;

  // res = 0
  // src1 = 79228162514264337593543950335;
  // src2 = 79228162514264337593543950335;
  // res - OverflowExeption
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b00000000000000000000000000000000;

  int result = s21_mul(src1, src2, &our_res);

  ck_assert_int_eq(1, result);
}
END_TEST

START_TEST(s21_s21_is_mul42) {
#line 24

  s21_decimal src1, src2, res, our_res;

  // res = 0
  // src1 = -79228162514264337593543950335;
  // src2 = -79228162514264337593543950335;
  // res - OverflowExeption
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b10000000000000000000000000000000;

  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b10000000000000000000000000000000;

  int result = s21_mul(src1, src2, &our_res);

  ck_assert_int_eq(1, result);
}
END_TEST

START_TEST(s21_s21_is_mul43) {
#line 46

  s21_decimal src1, src2, res, our_res;

  // res = 0
  // src1 = 792281625142643375935439503;
  // src2 = -792281625142643375935439503;
  // res - OverflowExeption
  src1.bits[0] = 0b00101000111101011100001010001111;
  src1.bits[1] = 0b11110101110000101000111101011100;
  src1.bits[2] = 0b00000010100011110101110000101000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00101000111101011100001010001111;
  src2.bits[1] = 0b11110101110000101000111101011100;
  src2.bits[2] = 0b00000010100011110101110000101000;
  src2.bits[3] = 0b10000000000000000000000000000000;

  int result = s21_mul(src1, src2, &our_res);

  ck_assert_int_eq(2, result);
}
END_TEST

START_TEST(s21_s21_is_mul44) {
#line 68

  s21_decimal src1, src2, res, our_res;

  // res = 0
  // src1 = -7922816251426433759354395033;
  // src2 = 7922816251426433759354395033;
  // res - OverflowExeption
  src1.bits[0] = 0b10011001100110011001100110011001;
  src1.bits[1] = 0b10011001100110011001100110011001;
  src1.bits[2] = 0b00011001100110011001100110011001;
  src1.bits[3] = 0b10000000000000000000000000000000;

  src2.bits[0] = 0b10011001100110011001100110011001;
  src2.bits[1] = 0b10011001100110011001100110011001;
  src2.bits[2] = 0b00011001100110011001100110011001;
  src2.bits[3] = 0b00000000000000000000000000000000;

  int result = s21_mul(src1, src2, &our_res);

  ck_assert_int_eq(2, result);
}
END_TEST

START_TEST(s21_s21_is_mul45) {
#line 90

  s21_decimal src1, src2, res, our_res;

  // res = 0
  // src1 = 11111123123123123123123123;
  // src2 = 11111123123123123123123;
  // res - OverflowExeption
  src1.bits[0] = 0b11100000110011111111001110110011;
  src1.bits[1] = 0b00110001000000100101101100100110;
  src1.bits[2] = 0b00000000000010010011000011011111;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00100110100111111111001110110011;
  src2.bits[1] = 0b01010101110011110001101100111010;
  src2.bits[2] = 0b00000000000000000000001001011010;
  src2.bits[3] = 0b00000000000000000000000000000000;

  int result = s21_mul(src1, src2, &our_res);

  ck_assert_int_eq(1, result);
}
END_TEST

START_TEST(s21_s21_is_mul46) {
#line 112

  s21_decimal src1, src2, res, our_res;

  // res = 0
  // src1 = -11111123123123123123123123;
  // src2 = 11111123123123123123123;
  // res - OverflowExeption
  src1.bits[0] = 0b11100000110011111111001110110011;
  src1.bits[1] = 0b00110001000000100101101100100110;
  src1.bits[2] = 0b00000000000010010011000011011111;
  src1.bits[3] = 0b10000000000000000000000000000000;

  src2.bits[0] = 0b00100110100111111111001110110011;
  src2.bits[1] = 0b01010101110011110001101100111010;
  src2.bits[2] = 0b00000000000000000000001001011010;
  src2.bits[3] = 0b00000000000000000000000000000000;

  int result = s21_mul(src1, src2, &our_res);

  ck_assert_int_eq(2, result);
}
END_TEST

START_TEST(s21_s21_is_mul47) {
#line 134

  s21_decimal src1, src2, res, our_res;

  // res = 0
  // src1 = 11111123123123123123123123;
  // src2 = -11111123123123123123123;
  // res - OverflowExeption
  src1.bits[0] = 0b11100000110011111111001110110011;
  src1.bits[1] = 0b00110001000000100101101100100110;
  src1.bits[2] = 0b00000000000010010011000011011111;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00100110100111111111001110110011;
  src2.bits[1] = 0b01010101110011110001101100111010;
  src2.bits[2] = 0b00000000000000000000001001011010;
  src2.bits[3] = 0b10000000000000000000000000000000;

  int result = s21_mul(src1, src2, &our_res);

  ck_assert_int_eq(2, result);
}
END_TEST

START_TEST(s21_s21_is_mul48) {
#line 156

  s21_decimal src1, src2, res, our_res;

  // res = 0
  // src1 = -11111123123123123123123123;
  // src2 = -11111123123123123123123;
  // res - OverflowExeption
  src1.bits[0] = 0b11100000110011111111001110110011;
  src1.bits[1] = 0b00110001000000100101101100100110;
  src1.bits[2] = 0b00000000000010010011000011011111;
  src1.bits[3] = 0b10000000000000000000000000000000;

  src2.bits[0] = 0b00100110100111111111001110110011;
  src2.bits[1] = 0b01010101110011110001101100111010;
  src2.bits[2] = 0b00000000000000000000001001011010;
  src2.bits[3] = 0b10000000000000000000000000000000;

  int result = s21_mul(src1, src2, &our_res);

  ck_assert_int_eq(1, result);
}
END_TEST

START_TEST(s21_s21_is_div45) {
#line 178

  s21_decimal src1, src2, res, our_res;

  // res = 0
  // src1 = 11111123123123123123123123;
  // src2 = 0;
  // res - DivideByZeroExeption
  src1.bits[0] = 0b11100000110011111111001110110011;
  src1.bits[1] = 0b00110001000000100101101100100110;
  src1.bits[2] = 0b00000000000010010011000011011111;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;

  int result = s21_div(src1, src2, &our_res);

  ck_assert_int_eq(3, result);
}
END_TEST

START_TEST(s21_s21_is_div49) {
#line 200

  s21_decimal src1, src2, res, our_res;

  // res = 0
  // src1 = -11111123123123123123123123;
  // src2 = 0;
  // res - DivideByZeroExeption
  src1.bits[0] = 0b11100000110011111111001110110011;
  src1.bits[1] = 0b00110001000000100101101100100110;
  src1.bits[2] = 0b00000000000010010011000011011111;
  src1.bits[3] = 0b10000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;

  int result = s21_div(src1, src2, &our_res);

  ck_assert_int_eq(3, result);
}
END_TEST

START_TEST(s21_s21_is_div50) {
#line 222

  s21_decimal src1, src2, res, our_res;

  // res = 0
  // src1 = 11111123123123123123123123;
  // src2 = 0;
  // res - DivideByZeroExeption
  src1.bits[0] = 0b11100000110011111111001110110011;
  src1.bits[1] = 0b00110001000000100101101100100110;
  src1.bits[2] = 0b00000000000010010011000011011111;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;

  int result = s21_div(src1, src2, &our_res);

  ck_assert_int_eq(3, result);
}
END_TEST

START_TEST(s21_s21_is_div51) {
#line 244

  s21_decimal src1, src2, res, our_res;

  // res = 0
  // src1 = -11111123123123123123123123;
  // src2 = 0;
  // res - DivideByZeroExeption
  src1.bits[0] = 0b11100000110011111111001110110011;
  src1.bits[1] = 0b00110001000000100101101100100110;
  src1.bits[2] = 0b00000000000010010011000011011111;
  src1.bits[3] = 0b10000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;

  int result = s21_div(src1, src2, &our_res);

  ck_assert_int_eq(3, result);
}
END_TEST

START_TEST(s21_s21_is_sub42) {
#line 266

  s21_decimal src1, src2, res, our_res;

  // res = 0
  // src1 = -79228162514264337593543950333;
  // src2 = 79228162514264337593543950333;
  // res - OverflowExeption
  src1.bits[0] = 0b11111111111111111111111111111101;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b10000000000000000000000000000000;

  src2.bits[0] = 0b11111111111111111111111111111101;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b00000000000000000000000000000000;

  int result = s21_sub(src1, src2, &our_res);

  ck_assert_int_eq(2, result);
}
END_TEST

START_TEST(s21_s21_is_sub43) {
#line 288

  s21_decimal src1, src2, res, our_res;

  // res = 0
  // src1 = -79228162514264337593543950333;
  // src2 = 79228162514264337593543950333;
  // res - OverflowExeption
  src1.bits[0] = 0b11111111111111111111111111111101;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b10000000000000000000000000000000;

  src2.bits[0] = 0b11111111111111111111111111111101;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b00000000000000000000000000000000;

  int result = s21_sub(src1, src2, &our_res);

  ck_assert_int_eq(2, result);
}
END_TEST

START_TEST(s21_s21_is_add41) {
#line 310

  s21_decimal src1, src2, res, our_res;

  // res = 0
  // src1 = 79228162514264337593543950335;
  // src2 = 79228162514264337593543950335;
  // res - OverflowExeption
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b00000000000000000000000000000000;

  int result = s21_add(src1, src2, &our_res);

  ck_assert_int_eq(1, result);
}
END_TEST

START_TEST(s21_s21_is_add42) {
#line 332

  s21_decimal src1, src2, res, our_res;

  // res = 0
  // src1 = -79228162514264337593543950333;
  // src2 = -79228162514264337593543950333;
  // res - OverflowExeption
  src1.bits[0] = 0b11111111111111111111111111111101;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b10000000000000000000000000000000;

  src2.bits[0] = 0b11111111111111111111111111111101;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b10000000000000000000000000000000;

  int result = s21_add(src1, src2, &our_res);

  ck_assert_int_eq(2, result);
}
END_TEST

Suite *s21_s21_is_border(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, s21_s21_is_mul41);
  tcase_add_test(tc1_1, s21_s21_is_mul42);
  tcase_add_test(tc1_1, s21_s21_is_mul43);
  tcase_add_test(tc1_1, s21_s21_is_mul44);
  tcase_add_test(tc1_1, s21_s21_is_mul45);
  tcase_add_test(tc1_1, s21_s21_is_mul46);
  tcase_add_test(tc1_1, s21_s21_is_mul47);
  tcase_add_test(tc1_1, s21_s21_is_mul48);
  tcase_add_test(tc1_1, s21_s21_is_div45);
  tcase_add_test(tc1_1, s21_s21_is_div49);
  tcase_add_test(tc1_1, s21_s21_is_div50);
  tcase_add_test(tc1_1, s21_s21_is_div51);
  tcase_add_test(tc1_1, s21_s21_is_sub42);
  tcase_add_test(tc1_1, s21_s21_is_sub43);
  tcase_add_test(tc1_1, s21_s21_is_add41);
  tcase_add_test(tc1_1, s21_s21_is_add42);

  return s1;
}
