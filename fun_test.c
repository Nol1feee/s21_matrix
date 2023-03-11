#include "s21_matrix.h"

int main() {
  matrix_t kek = {0};
  s21_create_matrix(5, 5, &kek);
  matrix_t k = {0};
  s21_create_matrix(5, 5, &k);
  matrix_t wow = {0};
  s21_create_matrix(5, 5, &wow);
    s21_eq_matrix(&kek, &k);
     for(int i = 0; i < 5; i++) {
         for(int j = 0; j < 5; j++) {
            k.matrix[i][j] = i * j;
        }
    }

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
   printf("%.0f ", k.matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n\n\n\n");
  s21_mult_number( &k, 2, &wow);

  		for(int i = 0; i < 5; i++) {
  				for(int j = 0; j < 5; j++) {
  						printf("%.0f ", wow.matrix[i][j]);
  				}
  				printf("\n");
  		}

printf("\n");
//		for(int i = 0; i < 5; i++) {
//				for(int j = 0; j < 5; j++) {
//						printf("%.0f ",
//									 k.matrix[i][j]);
//				}
//				printf("\n");
//		}
  return 0;
}