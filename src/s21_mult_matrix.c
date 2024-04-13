#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (check_matrix(A) || check_matrix(B) || result == NULL) return MATRIX_ERR;
  int res = check_for_mult(A, B);
  if (!res) {
    res = s21_create_matrix(A->rows, B->columns, result);
    if (!res) {
      for (int row = 0; row < A->rows; row++)
        for (int col = 0; col < B->columns; col++)
          for (int j = 0; j < A->columns; j++)
            result->matrix[row][col] += A->matrix[row][j] * B->matrix[j][col];
    }
  }
  return res;
}
