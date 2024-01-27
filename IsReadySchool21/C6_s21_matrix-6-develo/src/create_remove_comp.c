#include "s21_matrix.h"

////////////////Create and Remove////////////////
int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (rows <= 0 || columns <= 0) {
    return INCORRECT_MATRIX;
  }
  result->rows = rows;
  result->columns = columns;
  result->matrix = malloc(sizeof(double *) * rows);
  for (int i = 0; i < rows; i++) {
    result->matrix[i] = malloc(sizeof(double) * columns);
  }
  return OK;
}

void s21_remove_matrix(matrix_t *A) {
  if (A != NULL) {
    for (int i = 0; i < A->rows; i++) {
      free(A->matrix[i]);
    }
    free(A->matrix);
  }
}
////////////////////////////////////////////////

//////////////////Comparison////////////////////
int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  if (A->columns == 0 && B->columns == 0 && A->rows == 0 && B->rows == 0) {
    return 0;
  }
  if (A == NULL || B == NULL) {
    return 0;
  }
  if (A->rows != B->rows || A->columns != B->columns) {
    return 0;
  }
  if (A->rows <= 0 || A->columns <= 0 || B->rows <= 0 || B->columns <= 0) {
    return 0;
  }
  double f = 0;
  int result = 1;
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < B->columns; j++) {
      f = A->matrix[i][j] - B->matrix[i][j];
      if (fabs(f) > 0.000001) {
        result = 0;
        break;
      }
    }
    if (result == 1) {
      break;
    }
  }
  return result;
}
////////////////////////////////////////////////
