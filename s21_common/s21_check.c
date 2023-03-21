#include "../s21_matrix.h"

int s21_check_two_matrix(matrix_t *A, matrix_t *B) {
    if (!(A->matrix) || !(B -> matrix)){
        return 0;
    } else if (A -> rows <= 0 || B -> rows <= 0 || A -> columns <= 0
               || B -> columns <= 0) {
        return 0;
    } else if ((A->rows != B->rows) || (A->columns != B->columns)) {
        return 0;
    }
    return 1;
}

int s21_check_matrix(matrix_t *A) {
    if (!(A->matrix)){
        return 0;
    } else if (A -> rows <= 0 || A -> columns <= 0) {
        return 0;
    }
    return 1;
}

void s21_minor(int rows, int columns, matrix_t *orig, matrix_t *result) {
		if(!s21_create_matrix(orig -> rows - 1, orig -> columns - 1, result)) {
				int res_i = 0, res_j = 0;
				for(int i = 0; i < orig -> rows; i++) {
						for(int j = 0; j < orig -> columns; j++) {
								if(rows != i && columns != j) {
										result->matrix[res_i][res_j] = orig->matrix[i][j];
										res_j++;
								}
								if (res_j == result->columns) {
										res_j = 0;
										res_i++;
								}
						}
				}
		}
}

double s21_deter(matrix_t *orig) {
		int j = 0;
		double res = 0;
		matrix_t temp_mat = {0};
		if(orig -> rows == 1) {
				res = orig -> matrix[0][0];
		} else {
				for (; j < orig->rows; j++) {
						s21_minor(0, j, orig, &temp_mat);
						res += (j % 2 == 0 ? 1 : -1) * orig->matrix[0][j] * s21_deter(&temp_mat);
				}
		}
		return res;
}

int auto_fill_matrix(matrix_t *A) {
		int temp_rand = 0;
		for(int i = 0; i < A -> rows; i++) {
				for(int j = 2; j < A -> columns; j++) {
						A -> matrix[i][j] = rand();
						temp_rand += A -> matrix[i][j];
				}
				return temp_rand;
		}
}