#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (!s21_check_matrix(A) || (A->rows != A->columns)) {
    return FAILURE_INCORRECT;
  } else {
    int temp = s21_create_matrix(A->rows, A->columns, result);
    if (temp != 0) {
      return FAILURE_INCORRECT;
    }
  }

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      matrix_t temp_matrix = {0};
      s21_minor(i, j, A, &temp_matrix);
      result->matrix[i][j] =
          ((i + j) % 2 == 0 ? 1 : -1) * s21_deter(&temp_matrix);
      s21_remove_matrix(&temp_matrix);
    }
  }
  return 0;
}