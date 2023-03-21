#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum { SUCCESS, FAILURE_INCORRECT, FAILURE_CALC };

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

int s21_create_matrix(int rows, int columns, matrix_t *result); //test - done
void s21_remove_matrix(matrix_t *A); //test - i need it..?
int s21_eq_matrix(matrix_t *A, matrix_t *B); //test - done
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result); //test - done
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result); //test - done
int s21_mult_number(matrix_t *A, double number, matrix_t *result); //test - done
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result); //test - done
int s21_calc_complements(matrix_t *A, matrix_t *result); //test - done
int s21_determinant(matrix_t *A, double *result); //test - done
int s21_inverse_matrix(matrix_t *A, matrix_t *result); //test - done

// common
int s21_check_two_matrix(matrix_t *A, matrix_t *B);
int s21_check_matrix(matrix_t *A);
void s21_minor(int rows, int columns, matrix_t *orig, matrix_t *result);
double s21_deter(matrix_t *orig);
int auto_fill_matrix(matrix_t *A);
