#include <check.h>

#ifndef S21_TESTS_H
#define S21_TESTS_H
Suite *s21_s21_is_greater(void);
Suite *s21_s21_is_equal(void);
Suite *s21_s21_is_less(void);
Suite *s21_s21_not_equal(void);
Suite *s21_s21_is_greater_or_equal(void);
Suite *s21_s21_is_less_or_equal(void);

Suite *s21_s21_add(void);
Suite *s21_s21_add_2(void);
Suite *s21_s21_div(void);
Suite *s21_s21_mul(void);
Suite *s21_s21_sub(void);

Suite *s21_s21_from_float_to_decimal(void);
Suite *s21_s21_from_decimal_to_float(void);
Suite *s21_s21_from_int_to_decimal(void);
Suite *s21_s21_from_decimal_to_int(void);

Suite *s21_s21_truncate();
Suite *s21_s21_round();
Suite *s21_s21_negate();
Suite *s21_s21_floor();

Suite *s21_s21_is_border(void);
#endif