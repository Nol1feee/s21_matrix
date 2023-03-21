#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (!s21_check_matrix(A)) {
    return FAILURE_INCORRECT;
  } else if (s21_create_matrix(A->rows, A->columns, result)) {
    return FAILURE_CALC;
  } else {
    double one_more_tmp = 0;
    double tmp = s21_determinant(A, &one_more_tmp);
    if (one_more_tmp == 0 || tmp != 0) return FAILURE_CALC;
  }
  matrix_t temp = {0};
  s21_calc_complements(A, &temp);
  s21_transpose(&temp, result);
  for (int i = 0; i < result->rows; i++) {
    for (int j = 0; j < result->columns; j++) {
      result->matrix[i][j] = result->matrix[i][j] * -1;
    }
  }
  return 0;
}