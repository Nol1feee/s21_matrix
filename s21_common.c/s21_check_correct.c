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