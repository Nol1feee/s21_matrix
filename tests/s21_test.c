//#include <check.h>
#include "../s21_matrix.h"

#test create_matrix
matrix_t one = {0};
ck_assert (s21_create_matrix(5, 5, &one) == 0);
s21_remove_matrix(&one);

ck_assert (s21_create_matrix(0, 5, &one) == 1);
ck_assert (s21_create_matrix(5, 0, &one) == 1);
ck_assert (s21_create_matrix(-5, -5, &one) == 1);

#test eq_matrix_diff
matrix_t one = {0}, two = {0};
s21_create_matrix(3, 3, &one);
s21_create_matrix(3, 3, &two);
auto_fill_matrix(&one);
auto_fill_matrix(&two);
ck_assert (s21_eq_matrix(&one, &two) == 0);
s21_remove_matrix(&one);
s21_remove_matrix(&two);

#test eq_matrix_not_create
matrix_t one = {0}, two = {0};
s21_create_matrix(0, 3, &one);
s21_create_matrix(3, 3, &two);
ck_assert (s21_eq_matrix(&one, &two) == 0);
s21_remove_matrix(&two);

#test eq_matrix_eq
matrix_t one = {0}, two = {0};
s21_create_matrix(3, 3, &one);
s21_create_matrix(3, 3, &two);
for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
				one.matrix[i][j] = i + j;
				two.matrix[i][j] = i + j;
		}
}
ck_assert (s21_eq_matrix(&one, &two) == 1);
s21_remove_matrix(&one);
s21_remove_matrix(&two);

#test sum_matrix_one
matrix_t one = {0}, two = {0}, res = {0};
s21_create_matrix(0, 1, &one);
s21_create_matrix(0, 1, &two);
ck_assert (s21_sum_matrix(&one, &two, &res) == 1);

#test sum_matrix_two
matrix_t one = {0}, two = {0}, res = {0};
s21_create_matrix(1, 0, &one);
s21_create_matrix(1, 0, &two);
ck_assert (s21_sum_matrix(&one, &two, &res) == 1);

#test sum_matrix_three
matrix_t one = {0}, two = {0}, res = {0};
s21_create_matrix(1, 1, &one);
s21_create_matrix(1, 1, &two);
s21_create_matrix(0, 1, &res);
ck_assert (s21_sum_matrix(&one, &two, &res) == 1);
s21_remove_matrix(&one);
s21_remove_matrix(&two);

#test sum_matrix_four
matrix_t one = {0}, two = {0}, res = {0};
s21_create_matrix(1, 1, &one);
s21_create_matrix(2, 1, &two);
s21_create_matrix(1, 1, &res);
ck_assert (s21_sum_matrix(&one, &two, &res) == 1);
s21_remove_matrix(&one);
s21_remove_matrix(&two);
s21_remove_matrix(&res);

#test sum_matrix_five
//matrix 5x5
matrix_t one = {0}, two = {0}, res = {0}, expected = {0};

matrix_t *kek[] = {&one, &two, &res, &expected, NULL};
for(int i = 0; kek[i] != NULL; i++) {
s21_create_matrix(5, 5, kek[i]);
}

for(int i = 0; i < 5; i++) {
		for(int j = 0; j < 5; j++) {
				one.matrix[i][j] = i + j - 5;
				two.matrix[i][j] = i + j - 10;
				expected.matrix[i][j] = i + i + j + j - 15;
		}
}
s21_sum_matrix(&one, &two, &res);
ck_assert_int_eq(s21_eq_matrix(&res, &expected), 1);
for(int i = 0; kek[i] != NULL; i++) {
		s21_remove_matrix(kek[i]);
}

#test sum_matrix_six
//matrix 2x2
matrix_t one = {0}, two = {0}, res = {0}, expected = {0};

matrix_t *kek[] = {&one, &two, &res, &expected, NULL};
for(int i = 0; kek[i] != NULL; i++) {
s21_create_matrix(2, 2, kek[i]);
}

for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++) {
				one.matrix[i][j] = i + j + 5;
				two.matrix[i][j] = i + j + 10;
				expected.matrix[i][j] = i + i + j + j + 15;
		}
}
s21_sum_matrix(&one, &two, &res);
ck_assert_int_eq(s21_eq_matrix(&res, &expected), 1);
for(int i = 0; kek[i] != NULL; i++) {
		s21_remove_matrix(kek[i]);
}

#test sum_matrix_seven
//matrix 1x1
matrix_t one = {0}, two = {0}, res = {0}, expected = {0};

matrix_t *kek[] = {&one, &two, &res, &expected, NULL};
for(int i = 0; kek[i] != NULL; i++) {
s21_create_matrix(1, 1, kek[i]);
}

for(int i = 0; i < 1; i++) {
		for(int j = 0; j < 1; j++) {
				one.matrix[i][j] = i + j + 5;
				two.matrix[i][j] = i + j + 10;
				expected.matrix[i][j] = i + i + j + j + 15;
		}
}
s21_sum_matrix(&one, &two, &res);
ck_assert_int_eq(s21_eq_matrix(&res, &expected), 1);
for(int i = 0; kek[i] != NULL; i++) {
		s21_remove_matrix(kek[i]);
}

#test sub_matrix_one
matrix_t one = {0}, two = {0}, res = {0};
s21_create_matrix(0, 1, &one);
s21_create_matrix(0, 1, &two);
ck_assert (s21_sub_matrix(&one, &two, &res) == 1);

#test sub_matrix_two
matrix_t one = {0}, two = {0}, res = {0};
s21_create_matrix(1, 0, &one);
s21_create_matrix(1, 0, &two);
ck_assert (s21_sub_matrix(&one, &two, &res) == 1);

#test sub_matrix_three
matrix_t one = {0}, two = {0}, res = {0};
s21_create_matrix(1, 1, &one);
s21_create_matrix(1, 1, &two);
s21_create_matrix(0, 1, &res);
ck_assert (s21_sub_matrix(&one, &two, &res) == 1);
s21_remove_matrix(&one);
s21_remove_matrix(&two);

#test sub_matrix_four
matrix_t one = {0}, two = {0}, res = {0};
s21_create_matrix(1, 1, &one);
s21_create_matrix(2, 1, &two);
s21_create_matrix(1, 1, &res);
ck_assert (s21_sub_matrix(&one, &two, &res) == 1);
s21_remove_matrix(&one);
s21_remove_matrix(&two);
s21_remove_matrix(&res);

#test sub_matrix_five
//matrix 5x5
matrix_t one = {0}, two = {0}, res = {0}, expected = {0};
res.rows = 5, res.columns = 5;
matrix_t *kek[] = {&one, &two, &expected, NULL};
for(int i = 0; kek[i] != NULL; i++) {
		s21_create_matrix(5, 5, kek[i]);
}

for(int i = 0; i < 5; i++) {
		for(int j = 0; j < 5; j++) {
				one.matrix[i][j] = 5;
				two.matrix[i][j] = 10;
				expected.matrix[i][j] = 5 - 10;
		}
}
s21_sub_matrix(&one, &two, &res);
ck_assert_int_eq(s21_eq_matrix(&res, &expected), 1);
for(int i = 0; kek[i] != NULL; i++) {
s21_remove_matrix(kek[i]);
}

#test sub_matrix_six
//matrix 2x2
matrix_t one = {0}, two = {0}, res = {0}, expected = {0};

matrix_t *kek[] = {&one, &two, &res, &expected, NULL};
for(int i = 0; kek[i] != NULL; i++) {
		s21_create_matrix(2, 2, kek[i]);
}

for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++) {
				one.matrix[i][j] = i + j + 5;
				two.matrix[i][j] = i + j + 10;
				expected.matrix[i][j] = one.matrix[i][j] - two.matrix[i][j];
		}
}
s21_sub_matrix(&one, &two, &res);
ck_assert_int_eq(s21_eq_matrix(&res, &expected), 1);
for(int i = 0; kek[i] != NULL; i++) {
s21_remove_matrix(kek[i]);
}

#test sub_matrix_seven
//matrix 1x1
matrix_t one = {0}, two = {0}, res = {0}, expected = {0};

matrix_t *kek[] = {&one, &two, &res, &expected, NULL};
for(int i = 0; kek[i] != NULL; i++) {
s21_create_matrix(1, 1, kek[i]);
}

for(int i = 0; i < 1; i++) {
		for(int j = 0; j < 1; j++) {
				one.matrix[i][j] = i + j + 5;
				two.matrix[i][j] = i + j + 10;
				expected.matrix[i][j] = i + i + j + j - 15;
		}
}
s21_sub_matrix(&one, &two, &res);
ck_assert_int_eq(s21_eq_matrix(&res, &expected), 0);
for(int i = 0; kek[i] != NULL; i++) {
s21_remove_matrix(kek[i]);
}

#test mult_number_one
int rows_col = 5;
int mult = 3;
matrix_t A = {0}, res = {0}, expected = {0};
res.rows = rows_col, res.columns = rows_col;
s21_create_matrix(rows_col, rows_col, &A);
s21_create_matrix(rows_col, rows_col, &expected);
for(int i = 0; i < rows_col; i++) {
		for(int j = 0; j < rows_col; j++) {
				A.matrix[i][j] = i + j + 3;
				expected.matrix[i][j] = A.matrix[i][j] * mult;
		}
}
s21_mult_number(&A, mult, &res);
ck_assert(s21_eq_matrix(&res, &expected) == 1);
s21_remove_matrix(&res);
s21_remove_matrix(&expected);
s21_remove_matrix(&A);

#test mult_number_two
int rows_col = 5;
int mult = 3;
matrix_t A = {0}, res = {0}, expected = {0};
//res.rows = rows_col, res.columns = rows_col;
s21_create_matrix(rows_col, rows_col, &A);
s21_create_matrix(rows_col, rows_col, &expected);
for(int i = 0; i < rows_col; i++) {
for(int j = 0; j < rows_col; j++) {
A.matrix[i][j] = i + j + 3;
expected.matrix[i][j] = A.matrix[i][j] * mult;
}
}
s21_mult_number(&A, mult, &res);
ck_assert(s21_eq_matrix(&res, &expected) == 0);
s21_remove_matrix(&res);
s21_remove_matrix(&expected);
s21_remove_matrix(&A);

#test mult_number_three
int rows_col = 5;
int mult = 3;
matrix_t A = {0}, res = {0}, expected = {0};
res.rows = 3, res.columns = 3;
s21_create_matrix(rows_col, rows_col, &A);
s21_create_matrix(rows_col, rows_col, &expected);
for(int i = 0; i < rows_col; i++) {
for(int j = 0; j < rows_col; j++) {
A.matrix[i][j] = i + j + 3;
expected.matrix[i][j] = A.matrix[i][j] * mult;
}
}
s21_mult_number(&A, mult, &res);
ck_assert(s21_eq_matrix(&res, &expected) == 0);
s21_remove_matrix(&res);
s21_remove_matrix(&expected);
s21_remove_matrix(&A);

#test mult_number_four
int rows_col = 5;
int mult = rand();
matrix_t A = {0}, res = {0}, expected = {0};
res.rows = rows_col, res.columns = rows_col;
s21_create_matrix(rows_col, rows_col, &A);
s21_create_matrix(rows_col, rows_col, &expected);
for(int i = 0; i < rows_col; i++) {
for(int j = 0; j < rows_col; j++) {
A.matrix[i][j] = i + j + 3;
expected.matrix[i][j] = A.matrix[i][j] * mult;
}
}
s21_mult_number(&A, mult, &res);
ck_assert(s21_eq_matrix(&res, &expected) == 1);
s21_remove_matrix(&res);
s21_remove_matrix(&expected);
s21_remove_matrix(&A);

#test transpose_one
matrix_t A = {0}, res = {0};
s21_create_matrix(3, 3, &A);
ck_assert (s21_transpose(&A, &res) == 1);
s21_remove_matrix(&A);

#test transpose_two
matrix_t A = {0}, res = {0};
s21_create_matrix(3, 3, &res);
ck_assert (s21_transpose(&A, &res) == 1);
s21_remove_matrix(&res);

#test transpose_three
int count = 0;
matrix_t A = {0}, res = {0}, expected = {0};
res.rows = 3, res.columns = 2;
s21_create_matrix(2, 3, &A);
s21_create_matrix(3, 2, &expected);
s21_transpose(&A, &res);
for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 3; j++) {
				A.matrix[i][j] = count;
				count++;
		}
}
count = 5;
for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 2; j++) {
				expected.matrix[i][j] = count;
				count --;
		}
}
ck_assert (s21_eq_matrix(&expected, &res) == 0);
s21_remove_matrix(&res);
s21_remove_matrix(&A);
s21_remove_matrix(&expected);

#test calc_complements_one
matrix_t one = {0}, res = {0};
ck_assert (s21_calc_complements(&one, &res) == 1);

#test calc_complements_two
matrix_t A = {0}, res = {0}, expected = {0};

s21_create_matrix(3, 3, &A);
A.matrix[0][0] = 1;
A.matrix[0][1] = 2;
A.matrix[0][2] = 3;

A.matrix[1][0] = 0;
A.matrix[1][1] = 4;
A.matrix[1][2] = 2;

A.matrix[2][0] = 5;
A.matrix[2][1] = 2;
A.matrix[2][2] = 1;

s21_create_matrix(3, 3, &expected);
expected.matrix[0][0] = 0;
expected.matrix[0][1] = 10;
expected.matrix[0][2] = -20;

expected.matrix[1][0] = 4;
expected.matrix[1][1] = -14;
expected.matrix[1][2] = 8;

expected.matrix[2][0] = -8;
expected.matrix[2][1] = -2;
expected.matrix[2][2] = 4;

s21_calc_complements(&A, &res);
ck_assert (s21_eq_matrix(&res, &expected) == 1);

#test determinant_one
matrix_t one = {0};
double res = 0;
ck_assert (s21_determinant (&one, &res) == 1);

#test determinant_two
int count = 0;
double result = -5;
matrix_t one = {0}, res = {0};
s21_create_matrix(3, 3, &one);
for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
				one.matrix[i][j] = count;
				count++;
		}
}
ck_assert(s21_determinant(&one, &result) == 0);
ck_assert(result == 0);
s21_remove_matrix(&one);

#test inverse_one
matrix_t one = {0}, res = {0};
ck_assert(s21_inverse_matrix(&one, &res) == 1);

#test inverse_two
int count = 0;
matrix_t one = {0}, res = {0};
s21_create_matrix(3, 3, &one);
for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
				one.matrix[i][j] = count;
				count++;
		}
}
ck_assert(s21_inverse_matrix(&one, &res) == 2);

#test inverse_three
matrix_t A = {0}, res = {0}, expected = {0};
s21_create_matrix(3, 3, &A);
s21_create_matrix(3, 3, &expected);

A.matrix[0][0] = 2;
A.matrix[0][1] = 5;
A.matrix[0][2] = 7;

A.matrix[1][0] = 6;
A.matrix[1][1] = 3;
A.matrix[1][2] = 4;

A.matrix[2][0] = 5;
A.matrix[2][1] = -2;
A.matrix[2][2] = -3;

expected.matrix[0][0] = 1;
expected.matrix[0][1] = -1;
expected.matrix[0][2] = 1;

expected.matrix[1][0] = -38;
expected.matrix[1][1] = 41;
expected.matrix[1][2] = -34;

expected.matrix[2][0] = 27;
expected.matrix[2][1] = -29;
expected.matrix[2][2] = 24;
s21_inverse_matrix(&A, &res);
ck_assert(s21_eq_matrix(&expected, &res));
s21_remove_matrix(&A);
s21_remove_matrix(&expected);