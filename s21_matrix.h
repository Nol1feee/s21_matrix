#include <stdio.h>
#include <stdlib.h>
#include <math.h>

enum { SUCCESS, FAILURE_INCORRECT, FAILURE_CALC };

typedef struct matrix_struct {
		double **matrix;
		int rows;
		int columns;
} matrix_t;

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);