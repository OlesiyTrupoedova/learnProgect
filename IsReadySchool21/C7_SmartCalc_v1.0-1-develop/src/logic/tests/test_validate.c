#include "test.h"

START_TEST(test_validate_1) {
  char expression[] = "1+2-12*4/2";
  int error = validate(expression);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(test_validate_2) {
  char expression[] = "-3*5+12/(3-6)";
  int error = validate(expression);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(test_validate_3) {
  char expression[] = "2++2*3--5/5";
  int error = validate(expression);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(test_validate_4) {
  char expression[] = "2++(2*3)--5/5";
  int error = validate(expression);
  ck_assert_int_ne(error, 0);
}
END_TEST

START_TEST(test_validate_5) {
  char expression[] = "2+2*3-)(5/5";
  int error = validate(expression);
  ck_assert_int_ne(error, 0);
}
END_TEST

START_TEST(test_validate_6) {
  char expression[] = "()2+2*3-5/5";
  int error = validate(expression);
  ck_assert_int_ne(error, 0);
}
END_TEST

START_TEST(test_validate_10) {
  char expression[] = "2+2*3---5/cos(5)";
  int error = validate(expression);
  ck_assert_int_ne(error, 0);
}
END_TEST

START_TEST(test_validate_11) {
  char expression[] = "2 + 2 + * 3 - -5 / cos(5)";
  int error = validate(expression);
  ck_assert_int_ne(error, 0);
}
END_TEST

START_TEST(test_validate_12) {
  char expression[] = "2.0.0+2+(3--5)/(cos(5)";
  int error = validate(expression);
  ck_assert_int_ne(error, 0);
}
END_TEST

Suite *test_validate() {
  Suite *s;
  TCase *tc;

  s = suite_create("test_calc");
  tc = tcase_create("test_calc");
  tcase_add_test(tc, test_validate_1);
  tcase_add_test(tc, test_validate_2);
  tcase_add_test(tc, test_validate_3);
  tcase_add_test(tc, test_validate_4);
  tcase_add_test(tc, test_validate_5);
  tcase_add_test(tc, test_validate_6);
  tcase_add_test(tc, test_validate_10);
  tcase_add_test(tc, test_validate_11);
  tcase_add_test(tc, test_validate_12);
  suite_add_tcase(s, tc);
  return s;
}