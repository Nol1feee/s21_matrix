#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  if (!(A->matrix) || !(B -> matrix)){
    return FAILURE_INCORRECT;
  } else if (A -> rows <= 0 || B -> rows <= 0 || A -> columns <= 0
	|| B -> columns <= 0) {
    return FAILURE_INCORRECT;
  } else if ((A->rows != B->rows) || (A->columns != B->columns)) {
    return FAILURE_INCORRECT;
  }
  int res = 1;
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
				//объясни
      if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-07) {
        res = 0;
        break;
					//объясни
      }
    }
  }
  return res;
}