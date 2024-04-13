#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (check_matrix(A) || result == NULL) return MATRIX_ERR;
  int res = check_for_square(A);
  if (!res) {
    double determinant = 0;
    s21_determinant(A, &determinant);
    if (fabsl(determinant) <= 1.0E-7) {
      res = CALC_ERR;
    } else {
      s21_create_matrix(A->rows, A->columns, result);
      matrix_t complements;
      matrix_t transpose;
      s21_calc_complements(A, &complements);
      s21_transpose(&complements, &transpose);
      for (int row = 0; row < A->rows; ++row) {
        for (int col = 0; col < A->columns; ++col) {
          result->matrix[row][col] =
              1.0 / determinant * transpose.matrix[row][col];
        }
      }
      s21_remove_matrix(&complements);
      s21_remove_matrix(&transpose);
    }
  }
  return res;
}
