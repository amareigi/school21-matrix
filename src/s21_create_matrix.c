#include "s21_matrix.h"

void fill_zero_func(matrix_t *result) {
  for (int i = 0; i < result->rows; i++)
    for (int j = 0; j < result->columns; j++) result->matrix[i][j] = 0;
}

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int res = MATRIX_ERR;
  if (rows > 0 && columns > 0 && result != NULL) {
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double **)malloc(rows * sizeof(double *));
    if (result->matrix != NULL) {
      int fail_memory = 0;
      for (int row = 0; row < rows; row++) {
        result->matrix[row] = (double *)malloc(columns * sizeof(double));
        if (result->matrix[row] == NULL) {
          fail_memory = 1;
        }
      }
      if (fail_memory) {
        s21_remove_matrix(result);
      } else {
        fill_zero_func(result);
        res = OK;
      }
    }
  }
  return res;
}
