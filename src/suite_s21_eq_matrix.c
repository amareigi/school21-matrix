#include "matrix_suitecases.h"

START_TEST(eq_matrix_1) {
  matrix_t A, B;
  int res;
  s21_create_matrix(10, 10, &A);
  s21_create_matrix(10, 10, &B);

  fill_matrix(&A);
  fill_matrix(&B);

  res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(1, res);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_2) {
  matrix_t A, B;
  int res;
  s21_create_matrix(10, 10, &A);
  s21_create_matrix(10, 10, &B);

  fill_matrix(&A);
  A.matrix[0][0] = 9.9999;
  fill_matrix(&B);

  res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(0, res);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST
START_TEST(eq_matrix_3) {
  matrix_t A, B;
  int res;
  s21_create_matrix(9, 10, &A);
  s21_create_matrix(10, 10, &B);

  fill_matrix(&A);
  fill_matrix(&B);

  res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(0, res);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
START_TEST(eq_matrix_4) {
  matrix_t B;
  int res;
  s21_create_matrix(10, 10, &B);

  fill_matrix(&B);

  res = s21_eq_matrix(NULL, &B);
  ck_assert_int_eq(0, res);

  s21_remove_matrix(&B);
}
Suite *suite_s21_eq_matrix() {
  Suite *s = suite_create("s21_eq_matrix");
  TCase *tc = tcase_create("s21_eq_matrix");

  tcase_add_test(tc, eq_matrix_1);
  tcase_add_test(tc, eq_matrix_2);
  tcase_add_test(tc, eq_matrix_3);
  tcase_add_test(tc, eq_matrix_4);

  suite_add_tcase(s, tc);
  return s;
}
