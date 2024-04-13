#include "s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (check_matrix(A) || check_matrix(B) || result == NULL) return MATRIX_ERR;
  int res = check_for_calc(A, B);
  if (!res) {
    res = s21_create_matrix(A->rows, A->columns, result);
    if (!res) {
      for (int row = 0; row < A->rows; row++)
        for (int col = 0; col < A->columns; col++)
          result->matrix[row][col] = A->matrix[row][col] + B->matrix[row][col];
    }
  }
  return res;
}
