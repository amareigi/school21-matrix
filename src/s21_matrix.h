#ifndef SRC_S21_MATRIX_H_
#define SRC_S21_MATRIX_H_

#include "s21_matrix.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0

#define OK 0
#define MATRIX_ERR 1
#define CALC_ERR 2

typedef struct matrix_struct {
    double** matrix;
    int rows;
    int columns;
} matrix_t;

// s21_functions
int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

// help_func
int check_matrix(matrix_t *A);
int check_for_calc(matrix_t *A, matrix_t *B);
int check_for_mult(matrix_t *A, matrix_t *B);
int check_for_square(matrix_t *A);




int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_transpose(matrix_t *A, matrix_t *result);

int s21_calc_complements(matrix_t *A, matrix_t *result);

int s21_determinant(matrix_t *A, double *result);

int s21_inverse_matrix(matrix_t *A, matrix_t *result);
#endif

