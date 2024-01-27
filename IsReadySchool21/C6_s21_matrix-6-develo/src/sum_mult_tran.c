#include "s21_matrix.h"

//////////////////SUM AND SUB///////////////////
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (A == NULL || B == NULL) {
    return INCORRECT_MATRIX;
  }
  if (A->rows != B->rows || A->columns != B->columns) {
    return MATH_ERROR;
  }
  if (A->rows <= 0 || A->columns <= 0 || B->rows <= 0 || B->columns <= 0) {
    return MATH_ERROR;
  }
  s21_create_matrix(A->rows, A->columns, result);
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
    }
  }
  return OK;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (A == NULL || B == NULL) {
    return INCORRECT_MATRIX;
  }
  if (A->rows != B->rows || A->columns != B->columns) {
    return MATH_ERROR;
  }
  if (A->rows <= 0 || A->columns <= 0 || B->rows <= 0 || B->columns <= 0) {
    return MATH_ERROR;
  }
  s21_create_matrix(A->rows, A->columns, result);
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
    }
  }
  return OK;
}

////////////////////////////////////////////////

//////////////////////MULT//////////////////////

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  if (A == NULL) {
    return INCORRECT_MATRIX;
  }
  if (A->rows <= 0 || A->columns <= 0) {
    return MATH_ERROR;
  }
  if (number == INFINITY || number == -INFINITY || number == NAN) {
    return MATH_ERROR;
  }
  s21_create_matrix(A->rows, A->columns, result);
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] * number;
    }
  }
  return OK;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (A == NULL || B == NULL) {
    return INCORRECT_MATRIX;
  }
  if (A->columns != B->rows) {
    return MATH_ERROR;
  }
  if (A->rows <= 0 || A->columns <= 0 || B->rows <= 0 || B->columns <= 0) {
    return MATH_ERROR;
  }
  s21_create_matrix(A->rows, B->columns, result);
  for (int i = 0; i < result->rows; i++) {
    for (int j = 0; j < result->columns; j++) {
      result->matrix[i][j] = 0;
      for (int k = 0; k < A->columns; k++) {
        result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
      }
    }
  }
  return OK;
}
////////////////////////////////////////////////

//////////////////////TRAN//////////////////////
int s21_transpose(matrix_t *A, matrix_t *result) {
  if (A == NULL) {
    return INCORRECT_MATRIX;
  }
  if (A->rows <= 0 || A->columns <= 0) {
    return MATH_ERROR;
  }
  if (A->rows <= 0 || A->columns <= 0) {
    return MATH_ERROR;
  }
  s21_create_matrix(A->columns, A->rows, result);
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[j][i] = A->matrix[i][j];
    }
  }
  return OK;
}
////////////////////////////////////////////////