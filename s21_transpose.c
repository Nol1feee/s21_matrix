#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  if (!s21_check_matrix(A)) {
    return FAILURE_INCORRECT;
  } else {
    int temp = s21_create_matrix(result->rows, result->columns, result);
    if (temp != 0) {
      return FAILURE_INCORRECT;
    }
  }

  for (int i = 0; i < result->columns; i++) {
    for (int j = 0; j < result->rows; j++) {
      result->matrix[j][i] = A->matrix[i][j];
    }
  }
  return SUCCESS;
}