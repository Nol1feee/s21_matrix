#include "s21_matrix.h"

int main() {
  matrix_t kek = {0};
  s21_create_matrix(5, 5, &kek);
  matrix_t k = {0};
  s21_create_matrix(5, 5, &k);
  printf("\n%d\n", s21_eq_matrix(&kek, &k));
//  		for(int i = 0; i < 5; i++) {
//  				for(int j = 0; j < 5; j++) {
//  						printf("%.0f ",
//  kek.matrix[i][j]);
//  				}
//  				printf("\n");
//  		}
//printf("\n");
//		for(int i = 0; i < 5; i++) {
//				for(int j = 0; j < 5; j++) {
//						printf("%.0f ",
//									 k.matrix[i][j]);
//				}
//				printf("\n");
//		}
  return 0;
}