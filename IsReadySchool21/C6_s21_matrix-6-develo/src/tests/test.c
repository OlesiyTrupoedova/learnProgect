#include "test.h"

#include <stdlib.h>
#define assert_double(x, y) (fabsl(x - y) < 0.000001)
START_TEST(sum_error_0) {
  matrix_t M;
  s21_create_matrix(2, 2, &M);
  M.matrix[0][0] = 1;
  M.matrix[0][1] = 3;
  M.matrix[1][0] = 2;
  M.matrix[1][1] = 4;
  matrix_t R;
  s21_create_matrix(2, 2, &R);
  R.matrix[0][0] = 1;
  R.matrix[0][1] = 3;
  R.matrix[1][0] = 2;
  R.matrix[1][1] = 4;

  matrix_t RESULT;
  int error = s21_sum_matrix(&M, &R, &RESULT);

  s21_remove_matrix(&M);
  s21_remove_matrix(&R);
  s21_remove_matrix(&RESULT);
  ck_assert_double_eq(error, 0);
}
END_TEST

START_TEST(sum_error_1) {
  matrix_t *M = NULL;
  matrix_t R;
  s21_create_matrix(2, 2, &R);
  R.matrix[0][0] = 1;
  R.matrix[0][1] = 3;
  R.matrix[1][0] = 2;
  R.matrix[1][1] = 4;

  matrix_t RESULT;

  int error = s21_sum_matrix(M, &R, &RESULT);

  s21_remove_matrix(&R);
  ck_assert_double_eq(error, 1);
}
END_TEST

START_TEST(sum_error_2) {
  matrix_t M;
  s21_create_matrix(2, 2, &M);
  M.matrix[0][0] = 1;
  M.matrix[0][1] = 3;
  M.matrix[1][0] = 2;
  M.matrix[1][1] = 4;
  matrix_t R;
  s21_create_matrix(1, 2, &R);
  R.matrix[0][0] = 1;
  R.matrix[0][1] = 3;

  matrix_t RESULT;

  int error = s21_sum_matrix(&M, &R, &RESULT);

  s21_remove_matrix(&M);
  s21_remove_matrix(&R);
  ck_assert_double_eq(error, 2);
}
END_TEST

Suite *test_sum_matrix(void) {
  Suite *s = suite_create("-=S21_SUM_MATRIX=-");
  TCase *tc = tcase_create("sum_tc");
  tcase_add_test(tc, sum_error_0);
  tcase_add_test(tc, sum_error_1);
  tcase_add_test(tc, sum_error_2);

  suite_add_tcase(s, tc);

  return s;
}

START_TEST(transpose_error_0) {
  matrix_t M, R;
  s21_create_matrix(3, 3, &M);
  M.matrix[0][0] = 5;
  M.matrix[0][1] = 2;
  M.matrix[0][2] = 3;
  M.matrix[1][0] = 7.5;
  M.matrix[1][1] = 3.14;
  M.matrix[1][2] = 1;
  M.matrix[2][0] = 1;
  M.matrix[2][1] = 1;
  M.matrix[2][2] = 1;

  int error = s21_transpose(&M, &R);
  s21_remove_matrix(&M);
  s21_remove_matrix(&R);
  ck_assert_double_eq(error, 0);
}
END_TEST

START_TEST(transpose_error_0_1) {
  matrix_t M, R;
  s21_create_matrix(1, 3, &M);
  M.matrix[0][0] = 5;
  M.matrix[0][1] = 2;
  M.matrix[0][2] = 3;

  int error = s21_transpose(&M, &R);
  s21_remove_matrix(&M);
  s21_remove_matrix(&R);
  ck_assert_double_eq(error, 0);
}
END_TEST

START_TEST(transpose_error_1) {
  matrix_t *M = NULL, R;

  int error = s21_transpose(M, &R);
  ck_assert_double_eq(error, 1);
}
END_TEST

Suite *test_transpose(void) {
  Suite *s = suite_create("-=S21_TRANSPOSE=-");
  TCase *tc = tcase_create("transpose_tc");
  tcase_add_test(tc, transpose_error_0);
  tcase_add_test(tc, transpose_error_0_1);
  tcase_add_test(tc, transpose_error_1);

  suite_add_tcase(s, tc);

  return s;
}

START_TEST(sub_error_0) {
  matrix_t M;
  s21_create_matrix(2, 2, &M);
  M.matrix[0][0] = 12;
  M.matrix[0][1] = 3;
  M.matrix[1][0] = 2;
  M.matrix[1][1] = 4;
  matrix_t R;
  s21_create_matrix(2, 2, &R);
  R.matrix[0][0] = 1;
  R.matrix[0][1] = 3;
  R.matrix[1][0] = 2;
  R.matrix[1][1] = 4;

  matrix_t RESULT;

  int error = s21_sub_matrix(&M, &R, &RESULT);
  s21_remove_matrix(&M);
  s21_remove_matrix(&R);
  s21_remove_matrix(&RESULT);
  ck_assert_double_eq(error, 0);
}
END_TEST

START_TEST(sub_error_1) {
  matrix_t *M = NULL;
  matrix_t R;
  s21_create_matrix(2, 2, &R);
  R.matrix[0][0] = 1;
  R.matrix[0][1] = 3;
  R.matrix[1][0] = 2;
  R.matrix[1][1] = 4;

  matrix_t RESULT;

  int error = s21_sub_matrix(M, &R, &RESULT);

  s21_remove_matrix(&R);
  ck_assert_double_eq(error, 1);
}
END_TEST

START_TEST(sub_error_2) {
  matrix_t M;
  s21_create_matrix(2, 2, &M);
  M.matrix[0][0] = 1;
  M.matrix[0][1] = 3;
  M.matrix[1][0] = 2;
  M.matrix[1][1] = 4;
  matrix_t R;
  s21_create_matrix(1, 2, &R);
  R.matrix[0][0] = 1;
  R.matrix[0][1] = 3;

  matrix_t RESULT;

  int error = s21_sub_matrix(&M, &R, &RESULT);

  s21_remove_matrix(&M);
  s21_remove_matrix(&R);
  ck_assert_double_eq(error, 2);
}
END_TEST

Suite *test_sub_matrix(void) {
  Suite *s = suite_create("-=S21_SUB_MATRIX=-");
  TCase *tc = tcase_create("sub_tc");

  tcase_add_test(tc, sub_error_0);
  tcase_add_test(tc, sub_error_1);
  tcase_add_test(tc, sub_error_2);

  suite_add_tcase(s, tc);

  return s;
}

START_TEST(mult_n_error_0) {
  matrix_t M, R;
  s21_create_matrix(1, 1, &M);
  M.matrix[0][0] = 1;

  double number = 0;
  int error = s21_mult_number(&M, number, &R);
  ck_assert_double_eq(error, 0);

  s21_remove_matrix(&M);
  s21_remove_matrix(&R);
}
END_TEST

START_TEST(mult_n_error_1) {
  matrix_t *M = NULL;
  matrix_t R;
  double number = 0;
  int error = s21_mult_number(M, number, &R);
  ck_assert_double_eq(error, 1);
}
END_TEST

Suite *test_mult_number(void) {
  Suite *s = suite_create("-=S21_MULT_NUMBER=-");
  TCase *tc = tcase_create("mult_n_tc");

  tcase_add_test(tc, mult_n_error_0);
  tcase_add_test(tc, mult_n_error_1);

  suite_add_tcase(s, tc);

  return s;
}

START_TEST(mult_m_error_0) {
  matrix_t M;
  s21_create_matrix(3, 2, &M);
  M.matrix[0][0] = 1;
  M.matrix[0][1] = 4;
  M.matrix[1][0] = 2;
  M.matrix[1][1] = 5;
  M.matrix[2][0] = 3;
  M.matrix[2][1] = 6;
  matrix_t R;
  s21_create_matrix(2, 3, &R);
  R.matrix[0][0] = 1;
  R.matrix[0][1] = -1;
  R.matrix[0][2] = 1;
  R.matrix[1][0] = 2;
  R.matrix[1][1] = 3;
  R.matrix[1][2] = 4;

  matrix_t RESULT;

  int error = s21_mult_matrix(&M, &R, &RESULT);

  s21_remove_matrix(&M);
  s21_remove_matrix(&R);
  s21_remove_matrix(&RESULT);
  ck_assert_double_eq(error, 0);
}
END_TEST

START_TEST(mult_m_error_1) {
  matrix_t *M = NULL;
  matrix_t R;
  s21_create_matrix(2, 2, &R);
  R.matrix[0][0] = 1;
  R.matrix[0][1] = 3;
  R.matrix[1][0] = 2;
  R.matrix[1][1] = 4;

  matrix_t RESULT;

  int error = s21_mult_matrix(M, &R, &RESULT);

  s21_remove_matrix(&R);
  ck_assert_double_eq(error, 1);
}
END_TEST

START_TEST(mult_m_error_2) {
  matrix_t M;
  s21_create_matrix(2, 2, &M);
  M.matrix[0][0] = 1;
  M.matrix[0][1] = 3;
  M.matrix[1][0] = 2;
  M.matrix[1][1] = 4;
  matrix_t R;
  s21_create_matrix(1, 2, &R);
  R.matrix[0][0] = 1;
  R.matrix[0][1] = 3;

  matrix_t RESULT;

  int error = s21_mult_matrix(&M, &R, &RESULT);

  s21_remove_matrix(&M);
  s21_remove_matrix(&R);
  ck_assert_double_eq(error, 2);
}
END_TEST

Suite *test_mult_matrix(void) {
  Suite *s = suite_create("-=S21_MULT_MATRIX=-");
  TCase *tc = tcase_create("mult_m_tc");

  tcase_add_test(tc, mult_m_error_0);
  tcase_add_test(tc, mult_m_error_1);
  tcase_add_test(tc, mult_m_error_2);

  suite_add_tcase(s, tc);

  return s;
}

START_TEST(inverse_1x1) {
  matrix_t M, R;
  s21_create_matrix(1, 1, &M);
  M.matrix[0][0] = 2;

  int error = s21_inverse_matrix(&M, &R);
  ck_assert_double_eq(error, 0);

  s21_remove_matrix(&M);
  s21_remove_matrix(&R);
}
END_TEST

START_TEST(inverse_3x3) {
  matrix_t M, R;
  s21_create_matrix(3, 3, &M);
  M.matrix[0][0] = 2;
  M.matrix[0][1] = 5;
  M.matrix[0][2] = 7;
  M.matrix[1][0] = 9;
  M.matrix[1][1] = 3;
  M.matrix[1][2] = 4;
  M.matrix[2][0] = 5;
  M.matrix[2][1] = -2;
  M.matrix[2][2] = -3;

  int error = s21_inverse_matrix(&M, &R);
  ck_assert_double_eq(error, 0);

  s21_remove_matrix(&M);
  s21_remove_matrix(&R);
}
END_TEST

START_TEST(inverse_error_1) {
  matrix_t *M = NULL;
  matrix_t R;

  int error = s21_inverse_matrix(M, &R);
  ck_assert_double_eq(error, 1);
}
END_TEST

START_TEST(inverse_error_2) {
  matrix_t M, R;
  s21_create_matrix(2, 3, &M);

  int error = s21_inverse_matrix(&M, &R);
  ck_assert_double_eq(error, 2);

  s21_remove_matrix(&M);
}
END_TEST

START_TEST(inverse_error_2_det_0) {
  matrix_t M, R;
  s21_create_matrix(3, 3, &M);
  M.matrix[0][0] = 1;
  M.matrix[0][1] = 2;
  M.matrix[0][2] = 3;
  M.matrix[1][0] = 4;
  M.matrix[1][1] = 5;
  M.matrix[1][2] = 6;
  M.matrix[2][0] = 7;
  M.matrix[2][1] = 8;
  M.matrix[2][2] = 9;

  int error = s21_inverse_matrix(&M, &R);
  ck_assert_double_eq(error, 2);

  s21_remove_matrix(&M);
}

Suite *test_inverse_matrix(void) {
  Suite *s = suite_create("-=S21_INVERSE_MATRIX=-");
  TCase *tc = tcase_create("inverse_tc");

  tcase_add_test(tc, inverse_1x1);
  tcase_add_test(tc, inverse_3x3);
  tcase_add_test(tc, inverse_error_1);
  tcase_add_test(tc, inverse_error_2);
  tcase_add_test(tc, inverse_error_2_det_0);

  suite_add_tcase(s, tc);

  return s;
}

START_TEST(eq_matrix) {
  const int rows = rand() % 100 + 1;
  const int cols = rand() % 100 + 1;
  matrix_t m = {0};
  s21_create_matrix(rows, cols, &m);
  matrix_t mtx = {0};
  s21_create_matrix(rows, cols, &mtx);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      double rand_val = get_rand(DBL_MIN, DBL_MAX);
      m.matrix[i][j] = rand_val;
      mtx.matrix[i][j] = rand_val;
    }
  }
  ck_assert_int_eq(s21_eq_matrix(&m, &mtx), SUCCESS);
  s21_remove_matrix(&m);
  s21_remove_matrix(&mtx);
}
END_TEST

START_TEST(not_eq) {
  matrix_t m = {0};
  const int rows = rand() % 100 + 1;
  const int cols = rand() % 100 + 1;
  s21_create_matrix(rows, cols, &m);
  matrix_t mtx = {0};
  const int rows1 = rand() % 100 + 1;
  const int cols1 = rand() % 100 + 1;
  s21_create_matrix(rows1, cols1, &mtx);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      m.matrix[i][j] = get_rand(DBL_MIN, DBL_MAX) + 1;
    }
  }
  for (int i = 0; i < rows1; i++) {
    for (int j = 0; j < cols1; j++) {
      mtx.matrix[i][j] = get_rand(DBL_MIN, DBL_MAX);
    }
  }
  ck_assert_int_eq(s21_eq_matrix(&m, &mtx), 0);
  s21_remove_matrix(&m);
  s21_remove_matrix(&mtx);
}
END_TEST

START_TEST(not_eq1) {
  matrix_t m = {0};
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  rows = -rows;
  cols = -cols;
  s21_create_matrix(rows, cols, &m);
  matrix_t mtx = {0};
  const int rows1 = rand() % 100 + 1;
  const int cols1 = rand() % 100 + 1;
  s21_create_matrix(rows1, cols1, &mtx);
  ck_assert_int_eq(s21_eq_matrix(&m, &mtx), FAILURE);
  s21_remove_matrix(&m);
  s21_remove_matrix(&mtx);
}
END_TEST

START_TEST(zero_matrix) {
  matrix_t A = {0};
  matrix_t B = {0};
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(0, result);
}
END_TEST

START_TEST(zero_matrix_1) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(0, 0, &A);
  s21_create_matrix(0, 0, &B);
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(0, result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(casual_matrix_1) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &B);
  A.matrix[0][0] = 1;
  B.matrix[0][0] = 1;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(1, result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(casual_matrix_2) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &B);
  A.matrix[0][0] = 1;
  B.matrix[0][0] = 2;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(0, result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(casual_matrix_3) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 4;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(1, result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(casual_matrix_4) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 4;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(1, result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(casual_matrix_5) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1.01;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3.05;
  A.matrix[1][1] = 4;
  B.matrix[0][0] = 1.01;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 3.05;
  B.matrix[1][1] = 4;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(1, result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(casual_matrix_6) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1.01;
  A.matrix[0][1] = -2;
  A.matrix[1][0] = 3.05;
  A.matrix[1][1] = -4;
  B.matrix[0][0] = 1.01;
  B.matrix[0][1] = -2;
  B.matrix[1][0] = 3.05;
  B.matrix[1][1] = -4;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(1, result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(casual_matrix_7) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1.00000000234;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3.05;
  A.matrix[1][1] = 4;
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 3.05;
  B.matrix[1][1] = 4;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(1, result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(casual_matrix_8) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1.0001;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3.05;
  A.matrix[1][1] = 4;
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 3.05;
  B.matrix[1][1] = 4;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(0, result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *test_eq_matrix(void) {
  Suite *s = suite_create("-=S21_EQ_MATRIX=-");
  TCase *tc = tcase_create("eq_tc");

  tcase_add_test(tc, not_eq);
  tcase_add_loop_test(tc, eq_matrix, 0, 100);
  tcase_add_test(tc, not_eq1);

  tcase_add_test(tc, zero_matrix);
  tcase_add_test(tc, zero_matrix_1);
  tcase_add_test(tc, casual_matrix_1);
  tcase_add_test(tc, casual_matrix_2);
  tcase_add_test(tc, casual_matrix_3);
  tcase_add_test(tc, casual_matrix_4);
  tcase_add_test(tc, casual_matrix_5);
  tcase_add_test(tc, casual_matrix_6);
  tcase_add_test(tc, casual_matrix_7);
  tcase_add_test(tc, casual_matrix_8);

  suite_add_tcase(s, tc);

  return s;
}

START_TEST(det_1) {
  matrix_t M;
  s21_create_matrix(1, 1, &M);
  M.matrix[0][0] = 1;

  double det = 0;
  s21_determinant(&M, &det);
  s21_remove_matrix(&M);
  ck_assert_double_eq(det, 1);
}
END_TEST

START_TEST(det_2) {
  matrix_t M;
  s21_create_matrix(2, 2, &M);
  M.matrix[0][0] = 1;
  M.matrix[0][1] = 3;
  M.matrix[1][0] = 2;
  M.matrix[1][1] = 4;

  double det = 0;
  s21_determinant(&M, &det);
  s21_remove_matrix(&M);
  ck_assert_double_eq(det, -2);
}
END_TEST

START_TEST(det_3_1) {
  matrix_t M;
  s21_create_matrix(3, 3, &M);
  M.matrix[0][0] = 1;
  M.matrix[0][1] = 2;
  M.matrix[0][2] = 3;
  M.matrix[1][0] = 4;
  M.matrix[1][1] = 5;
  M.matrix[1][2] = 6;
  M.matrix[2][0] = 7;
  M.matrix[2][1] = 8;
  M.matrix[2][2] = 9;

  double det = 0;
  s21_determinant(&M, &det);
  s21_remove_matrix(&M);
  ck_assert_double_eq(det, 0);
}
END_TEST

START_TEST(det_4_1) {
  matrix_t M;
  double det = 0;
  s21_create_matrix(4, 4, &M);
  M.matrix[0][0] = 1;
  M.matrix[0][1] = 2;
  M.matrix[0][2] = 3;
  M.matrix[0][3] = 4;
  M.matrix[1][0] = 5;
  M.matrix[1][1] = 6;
  M.matrix[1][2] = 1;
  M.matrix[1][3] = 3;
  M.matrix[2][0] = 2;
  M.matrix[2][1] = 4;
  M.matrix[2][2] = 5;
  M.matrix[2][3] = 9;
  M.matrix[3][0] = 1;
  M.matrix[3][1] = 5;
  M.matrix[3][2] = 7;
  M.matrix[3][3] = 19;
  s21_determinant(&M, &det);
  s21_remove_matrix(&M);
  ck_assert_double_eq(det, -17);
}
END_TEST

START_TEST(det_3_2) {
  matrix_t M;
  s21_create_matrix(3, 3, &M);
  M.matrix[0][0] = 4;
  M.matrix[0][1] = 2;
  M.matrix[0][2] = 3;
  M.matrix[1][0] = 7.5;
  M.matrix[1][1] = 3.14;
  M.matrix[1][2] = 1;
  M.matrix[2][0] = 1;
  M.matrix[2][1] = 1;
  M.matrix[2][2] = 1;

  double det = 0;
  s21_determinant(&M, &det);
  s21_remove_matrix(&M);
  ck_assert_int_eq(assert_double(det, 8.64), 1);
}
END_TEST

START_TEST(det_error_0) {
  matrix_t M;
  s21_create_matrix(3, 3, &M);
  M.matrix[0][0] = 5;
  M.matrix[0][1] = 2;
  M.matrix[0][2] = 3;
  M.matrix[1][0] = 7.5;
  M.matrix[1][1] = 3.14;
  M.matrix[1][2] = 1;
  M.matrix[2][0] = 1;
  M.matrix[2][1] = 1;
  M.matrix[2][2] = 1;

  double det = 0;
  int error = s21_determinant(&M, &det);
  s21_remove_matrix(&M);
  ck_assert_double_eq(error, 0);
}
END_TEST

START_TEST(det_error_1) {
  matrix_t *M = NULL;

  double det = 0;
  int error = s21_determinant(M, &det);
  ck_assert_double_eq(error, 1);
}
END_TEST

START_TEST(det_error_2) {
  matrix_t M;
  s21_create_matrix(1, 3, &M);
  M.matrix[0][0] = 5;
  M.matrix[0][1] = 2;
  M.matrix[0][2] = 3;

  double det = 0;
  int error = s21_determinant(&M, &det);
  s21_remove_matrix(&M);
  ck_assert_double_eq(error, 2);
}
END_TEST

Suite *test_determinant(void) {
  Suite *s = suite_create("-=S21_DETERMINANT=-");
  TCase *tc = tcase_create("det_tc");

  tcase_add_test(tc, det_1);
  tcase_add_test(tc, det_2);
  tcase_add_test(tc, det_3_1);
  tcase_add_test(tc, det_3_2);
  tcase_add_test(tc, det_4_1);
  tcase_add_test(tc, det_error_0);
  tcase_add_test(tc, det_error_1);
  tcase_add_test(tc, det_error_2);

  suite_add_tcase(s, tc);

  return s;
}

START_TEST(create_1x1) {
  matrix_t M;
  int error = s21_create_matrix(1, 1, &M);
  M.matrix[0][0] = 2;

  ck_assert_double_eq(error, 0);

  s21_remove_matrix(&M);
}
END_TEST

START_TEST(create_error_1) {
  matrix_t M;
  int error = s21_create_matrix(-1, 66, &M);

  ck_assert_double_eq(error, 1);
}
END_TEST

Suite *test_create_matrix(void) {
  Suite *s = suite_create("-=S21_CREATE_MATRIX=-");
  TCase *tc = tcase_create("create_tc");

  tcase_add_test(tc, create_1x1);
  tcase_add_test(tc, create_error_1);

  suite_add_tcase(s, tc);

  return s;
}

START_TEST(compl_error_0) {
  matrix_t M, R;
  s21_create_matrix(3, 3, &M);
  M.matrix[0][0] = 1;
  M.matrix[0][1] = 2;
  M.matrix[0][2] = 3;
  M.matrix[1][0] = 0;
  M.matrix[1][1] = 4;
  M.matrix[1][2] = 2;
  M.matrix[2][0] = 5;
  M.matrix[2][1] = 2;
  M.matrix[2][2] = 1;

  int error = s21_calc_complements(&M, &R);
  s21_remove_matrix(&M);
  s21_remove_matrix(&R);
  ck_assert_double_eq(error, 0);
}
END_TEST

START_TEST(compl_error_1) {
  matrix_t *M = NULL, R;

  int error = s21_calc_complements(M, &R);
  ck_assert_double_eq(error, 1);
}
END_TEST

START_TEST(compl_error_2) {
  matrix_t M, R;
  s21_create_matrix(1, 3, &M);
  M.matrix[0][0] = 5;
  M.matrix[0][1] = 2;
  M.matrix[0][2] = 3;

  int error = s21_calc_complements(&M, &R);
  s21_remove_matrix(&M);
  ck_assert_double_eq(error, 2);
}
END_TEST

START_TEST(compl_4) {
  matrix_t M, R, R2;
  s21_create_matrix(3, 3, &R2);
  s21_create_matrix(3, 3, &M);
  M.matrix[0][0] = 1;
  M.matrix[0][1] = 2;
  M.matrix[0][2] = 3;
  M.matrix[1][0] = 4;
  M.matrix[1][1] = 5;
  M.matrix[1][2] = 6;
  M.matrix[2][0] = 7;
  M.matrix[2][1] = 8;
  M.matrix[2][2] = 1;

  R2.matrix[0][0] = -43;
  R2.matrix[0][1] = -38;
  R2.matrix[0][2] = -3;
  R2.matrix[1][0] = -22;
  R2.matrix[1][1] = -20;
  R2.matrix[1][2] = -6;
  R2.matrix[2][0] = -3;
  R2.matrix[2][1] = -6;
  R2.matrix[2][2] = -3;

  int error = s21_calc_complements(&M, &R);
  error = s21_eq_matrix(&R, &R2);
  s21_remove_matrix(&M);
  s21_remove_matrix(&R);
  s21_remove_matrix(&R2);
  ck_assert_double_eq(error, 0);
}
END_TEST

Suite *test_calc_complements(void) {
  Suite *s = suite_create("-=S21_CALC_COMPLEMENTS=-");
  TCase *tc = tcase_create("compl_tc");
  tcase_add_test(tc, compl_error_0);
  tcase_add_test(tc, compl_error_1);
  tcase_add_test(tc, compl_error_2);
  tcase_add_test(tc, compl_4);
  suite_add_tcase(s, tc);

  return s;
}

void run() {
  Suite *tests[] = {
      test_create_matrix(),
      test_eq_matrix(),
      test_sum_matrix(),
      test_sub_matrix(),
      test_mult_number(),
      test_mult_matrix(),
      test_transpose(),
      test_calc_complements(),
      test_determinant(),
      test_inverse_matrix(),
      NULL,
  };

  int total = 0, failed = 0;

  for (Suite **current = tests; *current; current++) {
    SRunner *sr = srunner_create(*current);
    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    total += srunner_ntests_run(sr);
    failed += srunner_ntests_failed(sr);

    srunner_free(sr);
  }

  printf(
      "\n"
      " total: %d "
      " failed: %d "
      " success: %d "
      "\n",
      total, failed, total - failed);
}

double get_rand(double min, double max) {
  double val = (double)rand() / RAND_MAX;
  return min + val * (max - min);
}

int main() {
  run();
  return 0;
}
