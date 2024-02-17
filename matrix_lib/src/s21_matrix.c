#include "s21_matrix.h"

#include <stdio.h>

//////////////////////CALC//////////////////////
void s21_minor(matrix_t *A, matrix_t *result, int row, int col) {
  int sub_i = 0, sub_j = 0;
  for (int k = 0; k < result->rows; k++) {
    if (k == row) {
      sub_i = 1;
    }
    sub_j = 0;
    for (int l = 0; l < result->columns; l++) {
      if (l == col) {
        sub_j = 1;
      }
      result->matrix[k][l] = A->matrix[k + sub_i][l + sub_j];
    }
  }
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (A == NULL) {
    return INCORRECT_MATRIX;
  }
  if (A->columns != A->rows) {
    return MATH_ERROR;
  }
  s21_create_matrix(A->rows, A->columns, result);
  if (result->rows == 1) {
    result->matrix[0][0] = 1;
  } else {
    matrix_t minor_matrix;
    s21_create_matrix(A->rows - 1, A->columns - 1, &minor_matrix);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        s21_minor(A, &minor_matrix, i, j);
        double minor;
        s21_determinant(&minor_matrix, &minor);
        result->matrix[i][j] = minor * pow(-1, i + j);
      }
    }
    s21_remove_matrix(&minor_matrix);
  }

  return OK;
}

int s21_determinant(matrix_t *A, double *result) {
  if (A == NULL) {
    return INCORRECT_MATRIX;
  }
  if (A->columns != A->rows || A->rows < 1) {
    return MATH_ERROR;
  }
  double det = 0;
  int s = 1;
  matrix_t sub_mx;
  double res;

  switch (A->rows) {
    case 1:
      *result = A->matrix[0][0];
      break;
    case 2:
      *result =
          A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
      break;
    default:
      s21_create_matrix(A->rows - 1, A->rows - 1, &sub_mx);

      for (int i = 0; i < A->rows; i++) {
        s21_minor(A, &sub_mx, 0, i);
        s21_determinant(&sub_mx, &res);
        det += (s * A->matrix[0][i] * res);
        s = -s;
      }
      s21_remove_matrix(&sub_mx);
      *result = det;
  }
  return OK;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (A == NULL) {
    return INCORRECT_MATRIX;
  }
  if (A->columns != A->rows) {
    return MATH_ERROR;
  }
  double det = 0;
  s21_determinant(A, &det);
  if (det == 0) {
    return 2;
  } else {
    matrix_t temp;
    matrix_t temp2;

    s21_calc_complements(A, &temp);
    s21_transpose(&temp, &temp2);
    s21_mult_number(&temp2, 1 / det, result);
    s21_remove_matrix(&temp);
    s21_remove_matrix(&temp2);
  }

  return OK;
}
