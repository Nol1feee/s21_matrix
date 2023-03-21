#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  if (!s21_check_matrix(A) || A->rows != A->columns) {
    return FAILURE_INCORRECT;
  }

  *result = s21_deter(A);

  return SUCCESS;
}