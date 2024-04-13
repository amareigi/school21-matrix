#ifndef S_SRC_MATRIX_SUITECASES_H_
#define S_SRC_MATRIX_SUITECASES_H_

#include "s21_matrix.h"
#include <check.h>
//suits
Suite *suite_s21_create_matrix(void);
Suite *suite_s21_remove_matrix(void);
Suite *suite_s21_eq_matrix(void);
Suite *suite_s21_sum_matrix(void);
Suite *suite_s21_sub_matrix(void);
Suite *suite_s21_mult_matrix(void);
Suite *suite_s21_mult_number(void);
Suite *suite_s21_transpose(void);
Suite *suite_s21_determinant(void);
Suite *suite_s21_calc_complements(void);
Suite *suite_s21_inverse_matrix(void);


void fill_matrix(matrix_t *mat);
void print_matrix(matrix_t *mat);

void run_tests(void);
void run_testcase(Suite *testcase);

#endif

