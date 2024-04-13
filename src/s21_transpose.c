#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  if (check_matrix(A) || result == NULL) return MATRIX_ERR;
  int res = s21_create_matrix(A->columns, A->rows, result);
  if (!res) {
    for (int row = 0; row < A->columns; row++)
      for (int col = 0; col < A->rows; col++)
        result->matrix[row][col] = A->matrix[col][row];
  }
  return res;
}
