#include "s21_matrix.h"

int check_matrix(matrix_t *A) {
  int check;
  if (A == NULL)
    check = MATRIX_ERR;
  else if (A->rows < 1 || A->columns < 1 || A->matrix == NULL)
    check = MATRIX_ERR;
  else
    check = OK;
  return check;
}

int check_for_calc(matrix_t *A, matrix_t *B) {
  int check;
  if (A->columns != B->columns || A->rows != B->rows)
    check = CALC_ERR;
  else
    check = OK;
  return check;
}
int check_for_mult(matrix_t *A, matrix_t *B) {
  int check;
  if (A->columns != B->rows)
    check = CALC_ERR;
  else
    check = OK;
  return check;
}
int check_for_square(matrix_t *A) {
  int check;
  if (A->columns != A->rows)
    check = CALC_ERR;
  else
    check = OK;
  return check;
}
