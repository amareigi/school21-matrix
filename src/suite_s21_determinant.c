#include "matrix_suitecases.h"

START_TEST(determinant_1) {
  matrix_t A;
  int res;
  double det;
  double check_det = 0.0;
  s21_create_matrix(3, 3, &A);

  fill_matrix(&A);

  res = s21_determinant(&A, &det);
  ck_assert_int_eq(0, res);
  ck_assert_double_eq_tol(check_det, det, 1e-7);

  s21_remove_matrix(&A);
}
END_TEST
START_TEST(determinant_2) {
  matrix_t A;
  int res;
  double det;
  s21_create_matrix(3, 4, &A);

  fill_matrix(&A);

  res = s21_determinant(&A, &det);
  ck_assert_int_eq(2, res);

  s21_remove_matrix(&A);
}
END_TEST
START_TEST(determinant_3) {
  matrix_t A;
  int res;
  s21_create_matrix(3, 3, &A);

  fill_matrix(&A);

  res = s21_determinant(&A, NULL);
  ck_assert_int_eq(1, res);

  s21_remove_matrix(&A);
}
END_TEST
START_TEST(determinant_4) {
  matrix_t A;
  int res;
  double det;
  double check_det = 0.0;
  s21_create_matrix(3, 3, &A);

  res = s21_determinant(&A, &det);
  ck_assert_int_eq(0, res);
  ck_assert_double_eq_tol(check_det, det, 1e-7);

  s21_remove_matrix(&A);
}
END_TEST
START_TEST(determinant_5) {
  matrix_t A;
  int res;
  double det;
  double check_det = 0.0;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;

  res = s21_determinant(&A, &det);
  ck_assert_int_eq(0, res);
  ck_assert_double_eq_tol(check_det, det, 1e-7);

  s21_remove_matrix(&A);
}
END_TEST
Suite *suite_s21_determinant() {
  Suite *s = suite_create("s21_determinant");
  TCase *tc = tcase_create("s21_determinant");

  tcase_add_test(tc, determinant_1);
  tcase_add_test(tc, determinant_2);
  tcase_add_test(tc, determinant_3);
  tcase_add_test(tc, determinant_4);
  tcase_add_test(tc, determinant_5);

  suite_add_tcase(s, tc);
  return s;
}
