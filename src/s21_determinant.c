#include "s21_matrix.h"

void copy_matrix_func(matrix_t *A, matrix_t *copy) {
  s21_create_matrix(A->rows, A->columns, copy);
  for (int i = 0; i < copy->rows; i++)
    for (int j = 0; j < copy->rows; j++) copy->matrix[i][j] = A->matrix[i][j];
}

int s21_determinant(matrix_t *A, double *result) {
  if (check_matrix(A) || result == NULL) {
    return MATRIX_ERR;
  } else if (check_for_square(A)) {
    return CALC_ERR;
  }
  matrix_t copy;
  copy_matrix_func(A, &copy);
  int sign = 1;
  *result = 1.0;
  //метод гауса определитель
  for (int rows = 0; rows < copy.rows - 1 && *result; rows++) {
    int has_num = 0, zero_mat = 1;
    double *tmp = NULL;
    for (has_num = rows, zero_mat = 1; has_num < copy.rows; has_num++)
      if (copy.matrix[has_num][rows]) {  //проверяем проходя вниз по столбцу
        tmp = copy.matrix[has_num];  //адрес строки с ненулевым элементом
        zero_mat = 0;
        break;
      }
    //если элемент диагонали равен нулю и есть ненулевой элемент в другой строке
    //в этом столбце
    if (copy.matrix[rows][rows] == 0.0 && tmp != NULL) {
      copy.matrix[has_num] = copy.matrix[rows];  //меняем строки местами
      copy.matrix[rows] = tmp;
      sign = -sign;  // меняется знак оперделителя если меняем строки местами
    }

    if (zero_mat) {  //если все нули в столбце, опеределитель 0
      *result = 0.0;
    } else {
      for (int i = rows + 1; i < copy.rows;
           i++) {  //изменяем строку, где вставляем ноль
        double k = copy.matrix[i][rows] / copy.matrix[rows][rows];
        for (int j = rows; j < copy.columns; j++)
          copy.matrix[i][j] -= copy.matrix[rows][j] * k;
      }
    }
  }
  for (int i = 0; i < A->rows; i++) *result *= copy.matrix[i][i];
  *result *= sign;
  s21_remove_matrix(&copy);
  return OK;
}
