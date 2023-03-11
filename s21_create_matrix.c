#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (rows <= 0 || columns <= 0) {
    return FAILURE_INCORRECT;
  }

  int res = SUCCESS;
  result->rows = rows;
  result->columns = columns;
  result->matrix = calloc(rows, sizeof(double *));
  if (!(result->matrix)) {
    res = FAILURE_CALC;
  } else {
    for (int i = 0; i < rows; i++) {
      result->matrix[i] = calloc(columns, sizeof(double));
      if (!(result->matrix[i])) {
        for (; i > -1; i--) {
          free(result->matrix[i]);
        }
        free(result->matrix);
        res = FAILURE_INCORRECT;
        break;
      }
    }
  }
  return res;
}