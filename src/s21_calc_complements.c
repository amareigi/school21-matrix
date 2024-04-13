#include "s21_matrix.h"

void s21_minor_func(int delet_row, int delet_col, matrix_t *A,
                    matrix_t *minor) {
  if (check_matrix(A) || check_matrix(minor)) {
    ;
  } else {
    for (int row = 0, min_row = 0; row < A->rows; row++) {
      if (row != delet_row) {
        for (int col = 0, min_col = 0; col < A->columns; col++)
          if (col != delet_col) {
            minor->matrix[min_row][min_col] = A->matrix[row][col];
            min_col++;
          }
        min_row++;
      }
    }
  }
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (check_matrix(A) || result == NULL) return MATRIX_ERR;
  int res = check_for_square(A);
  if (!res) {
    res = s21_create_matrix(A->rows, A->columns, result);
    if (!res && A->rows == 1) {
      result->matrix[0][0] = 1.0;
    } else {
      for (int row = 0; row < A->rows && A->rows > 1; row++)
        for (int col = 0; col < A->columns; col++) {
          double determinant = 0;
          matrix_t minor;
          s21_create_matrix(A->rows - 1, A->columns - 1, &minor);
          s21_minor_func(row, col, A, &minor);
          s21_determinant(&minor, &determinant);
          result->matrix[row][col] = determinant * powl(-1.0, row + col);
          s21_remove_matrix(&minor);
        }
    }
  }
  return res;
}
