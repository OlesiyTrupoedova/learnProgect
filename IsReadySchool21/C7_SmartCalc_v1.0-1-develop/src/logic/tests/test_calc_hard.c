#include "test.h"

START_TEST(test_calc_hard_1) {
  int error = 0;
  char expression[] = "1+(2-12)*4/2+sin(0--0.324)-cos(1)";
  error = validate(expression);
  char *expression2 = polish_notation(expression);
  ck_assert_int_eq(
      assert_double(calculation(expression2, 0, 0, &error), -19.2219413302), 1);
  free(expression2);
}
END_TEST

START_TEST(test_calc_hard_2) {
  int error = 0;
  char expression[] = "(2.897/(3.97+4--5.0008*(-3.11-5)))*(2.12-3)";
  validate(expression);
  char *expression2 = polish_notation(expression);
  ck_assert_int_eq(
      assert_double(calculation(expression2, 0, 0, &error), 0.07823365316), 1);
  free(expression2);
}
END_TEST

START_TEST(test_calc_hard_4) {
  int error = 0;
  char expression[] =
      "(2.897/(3.97+4--5.0008*(-3.11 - -5)))*(2.12-3)-sin(0-"
      "-0.324)-cos(1)*(-2.897/(3.97+4--5.0008*cos(-3.11-5)))*"
      "sin(2.12-+3)";
  validate(expression);
  char *expression2 = polish_notation(expression);
  ck_assert_int_eq(
      assert_double(calculation(expression2, 0, 0, &error), -0.64465734987), 1);
  free(expression2);
}
END_TEST

START_TEST(test_calc_hard_5) {
  int error = 0;
  char expression[] =
      "-2-2--2+1094.232324-sin(1-0.32246+0.13253)/(200000.12/3)-tan(2)";
  validate(expression);
  char *expression2 = polish_notation(expression);
  ck_assert_int_eq(
      assert_double(calculation(expression2, 0, 0, &error), 1094.417353), 1);
  free(expression2);
}
END_TEST

START_TEST(test_calc_hard_6) {
  int error = 0;
  char expression[] = "((((12+4)/-2)--2)+5)/(sin(3)--2)";
  validate(expression);
  char *expression2 = polish_notation(expression);
  ck_assert_int_eq(
      assert_double(calculation(expression2, 0, 0, &error), -0.46704528295), 1);
  free(expression2);
}
END_TEST

START_TEST(test_calc_hard_7) {
  int error = 0;
  char expression[] =
      "(-2-2--2++1094.232324-sin(1-0.32246++0.13253)/(200000.12/3)-tan(2))/"
      "(((12++4)/-2)--2)++5";
  validate(expression);
  char *expression2 = polish_notation(expression);
  long double x = calculation(expression2, 0, 0, &error);
  ck_assert_int_eq(assert_double(x, -177.402892166), 1);
  free(expression2);
}
END_TEST

START_TEST(test_calc_hard_8) {
  int error = 0;
  char expression[] = "9mod(3)*2-7/7";
  validate(expression);
  char *expression2 = polish_notation(expression);
  long double result = calculation(expression2, 0, 0, &error);
  ck_assert_int_eq(assert_double(result, -1), 1);
  free(expression2);
}
END_TEST

START_TEST(test_calc_hard_9) {
  int error = 0;
  char expression[] = "acos(1)-asin(1)-atan(1)";
  validate(expression);
  char *expression2 = polish_notation(expression);
  ck_assert_int_eq(
      assert_double(calculation(expression2, 0, 0, &error), -2.35619449), 1);
  free(expression2);
}
END_TEST

START_TEST(test_calc_hard_10) {
  int error = 0;
  char expression[] = "log(100)+ln(2^2^2)";
  validate(expression);
  char *expression2 = polish_notation(expression);
  ck_assert_int_eq(
      assert_double(calculation(expression2, 0, 0, &error), 4.77258872224), 1);
  free(expression2);
}
END_TEST

START_TEST(test_calc_hard_11) {
  int error = 0;
  char expression[] = "1+2^-2+3^3-3";
  validate(expression);
  char *expression2 = polish_notation(expression);
  ck_assert_int_eq(assert_double(calculation(expression2, 0, 0, &error), 25.25),
                   1);
  free(expression2);
}
END_TEST

START_TEST(test_calc_hard_12) {
  int error = 0;
  char expression[] = "sqrt(1+2^-2+3^3-3)";
  validate(expression);
  char *expression2 = polish_notation(expression);
  ck_assert_int_eq(
      assert_double(calculation(expression2, 0, 0, &error), 5.02493781056), 1);
  free(expression2);
}
END_TEST

Suite *test_calc_hard() {
  Suite *s;
  TCase *tc;

  s = suite_create("test_calc");
  tc = tcase_create("test_calc");
  tcase_add_test(tc, test_calc_hard_1);
  tcase_add_test(tc, test_calc_hard_2);
  tcase_add_test(tc, test_calc_hard_4);
  tcase_add_test(tc, test_calc_hard_5);
  tcase_add_test(tc, test_calc_hard_6);
  tcase_add_test(tc, test_calc_hard_7);
  tcase_add_test(tc, test_calc_hard_8);
  tcase_add_test(tc, test_calc_hard_9);
  tcase_add_test(tc, test_calc_hard_10);
  tcase_add_test(tc, test_calc_hard_11);
  tcase_add_test(tc, test_calc_hard_12);
  suite_add_tcase(s, tc);
  return s;
}