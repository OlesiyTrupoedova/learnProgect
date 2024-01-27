#include "test.h"

#include <check.h>
#include <stdio.h>

#include "../s21_decimal.h"

int main() {
  int bitsber_failed = 0;
  SRunner *sr;
  Suite *decimal_suite;

  decimal_suite = s21_s21_is_less();
  sr = srunner_create(decimal_suite);
  srunner_run_all(sr, CK_NORMAL);
  bitsber_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  decimal_suite = s21_s21_is_less_or_equal();
  sr = srunner_create(decimal_suite);
  srunner_run_all(sr, CK_NORMAL);
  bitsber_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  decimal_suite = s21_s21_is_greater();
  sr = srunner_create(decimal_suite);
  srunner_run_all(sr, CK_NORMAL);
  bitsber_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  decimal_suite = s21_s21_not_equal();
  sr = srunner_create(decimal_suite);
  srunner_run_all(sr, CK_NORMAL);
  bitsber_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  decimal_suite = s21_s21_is_equal();
  sr = srunner_create(decimal_suite);
  srunner_run_all(sr, CK_NORMAL);
  bitsber_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  decimal_suite = s21_s21_is_greater_or_equal();
  sr = srunner_create(decimal_suite);
  srunner_run_all(sr, CK_NORMAL);
  bitsber_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  decimal_suite = s21_s21_add();
  sr = srunner_create(decimal_suite);
  srunner_run_all(sr, CK_NORMAL);
  bitsber_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  decimal_suite = s21_s21_add_2();
  sr = srunner_create(decimal_suite);
  srunner_run_all(sr, CK_NORMAL);
  bitsber_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  decimal_suite = s21_s21_div();
  sr = srunner_create(decimal_suite);
  srunner_run_all(sr, CK_NORMAL);
  bitsber_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  decimal_suite = s21_s21_mul();
  sr = srunner_create(decimal_suite);
  srunner_run_all(sr, CK_NORMAL);
  bitsber_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  decimal_suite = s21_s21_sub();
  sr = srunner_create(decimal_suite);
  srunner_run_all(sr, CK_NORMAL);
  bitsber_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  decimal_suite = s21_s21_truncate();
  sr = srunner_create(decimal_suite);
  srunner_run_all(sr, CK_NORMAL);
  bitsber_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  decimal_suite = s21_s21_floor();
  sr = srunner_create(decimal_suite);
  srunner_run_all(sr, CK_NORMAL);
  bitsber_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  decimal_suite = s21_s21_negate();
  sr = srunner_create(decimal_suite);
  srunner_run_all(sr, CK_NORMAL);
  bitsber_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  decimal_suite = s21_s21_round();
  sr = srunner_create(decimal_suite);
  srunner_run_all(sr, CK_NORMAL);
  bitsber_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  decimal_suite = s21_s21_from_float_to_decimal();
  sr = srunner_create(decimal_suite);
  srunner_run_all(sr, CK_NORMAL);
  bitsber_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  decimal_suite = s21_s21_from_decimal_to_float();
  sr = srunner_create(decimal_suite);
  srunner_run_all(sr, CK_NORMAL);
  bitsber_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  decimal_suite = s21_s21_from_decimal_to_int();
  sr = srunner_create(decimal_suite);
  srunner_run_all(sr, CK_NORMAL);
  bitsber_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  decimal_suite = s21_s21_from_int_to_decimal();
  sr = srunner_create(decimal_suite);
  srunner_run_all(sr, CK_NORMAL);
  bitsber_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  decimal_suite = s21_s21_is_border();
  sr = srunner_create(decimal_suite);
  srunner_run_all(sr, CK_NORMAL);
  bitsber_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return 0;
}