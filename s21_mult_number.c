#include "s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int temp = s21_create_matrix(result->rows, result->columns, result);
  if (temp != 0) {
    return temp;
  } else if (!s21_check_two_matrix(A, result)) {
    return FAILURE_INCORRECT;
  }

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] * number;
    }
  }
  return SUCCESS;
}