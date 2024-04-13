#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int res = SUCCESS;
  if (check_matrix(A) || check_matrix(B)) return FAILURE;
  if (A->columns != B->columns || A->rows != B->rows) {
    res = FAILURE;
  } else {
    for (int row = 0; row < A->rows && res; row++)
      for (int col = 0; col < A->columns && res; col++)
        if (fabs(A->matrix[row][col] - B->matrix[row][col]) >= 1.0E-7)
          res = FAILURE;
  }
  return res;
}
