#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (!s21_check_matrix(A) || !s21_check_matrix(B)) {
    return FAILURE_INCORRECT;
  } else if (A->columns != B->rows) {
    return FAILURE_INCORRECT;
  } else {
    int temp = s21_create_matrix(result->rows, result->columns, result);
    if (temp != 0) {
      return temp;
    }
  }

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      for (int k = 0; k < A->columns; k++) {
        result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
      }
    }
  }
  return SUCCESS;
}