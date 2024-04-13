#include "matrix_suitecases.h"

START_TEST(mult_number_1) {
  matrix_t A, R, check;
  int res;
  double num = 3.0;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &check);

  fill_matrix(&A);

  check.matrix[0][0] = 0;
  check.matrix[0][1] = 3;
  check.matrix[1][0] = 3;
  check.matrix[1][1] = 6;
  res = s21_mult_number(&A, num, &R);
  ck_assert_int_eq(0, res);

  res = s21_eq_matrix(&R, &check);
  ck_assert_int_eq(1, res);

  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
  s21_remove_matrix(&check);
}
END_TEST
START_TEST(mult_number_2) {
  matrix_t B, check;
  int res;
  double num = 3.0;
  s21_create_matrix(2, 2, &B);
  s21_create_matrix(2, 2, &check);

  res = s21_mult_number(&B, num, NULL);
  ck_assert_int_eq(1, res);

  s21_remove_matrix(&B);
  s21_remove_matrix(&check);
}
END_TEST
START_TEST(mult_number_3) {
  int res;
  double num = 3.0;
  res = s21_mult_number(NULL, num, NULL);
  ck_assert_int_eq(1, res);
}
END_TEST

Suite *suite_s21_mult_number() {
  Suite *s = suite_create("s21_mult_number");
  TCase *tc = tcase_create("s21_mult_number");

  tcase_add_test(tc, mult_number_1);
  tcase_add_test(tc, mult_number_2);
  tcase_add_test(tc, mult_number_3);

  suite_add_tcase(s, tc);
  return s;
}
