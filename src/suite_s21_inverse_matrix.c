#include "matrix_suitecases.h"

START_TEST(inverse_matrix_1) {
  matrix_t A, R;
  int res;
  s21_create_matrix(2, 3, &A);

  fill_matrix(&A);

  res = s21_inverse_matrix(&A, &R);
  ck_assert_int_eq(2, res);

  s21_remove_matrix(&A);
}
END_TEST
START_TEST(inverse_matrix_2) {
  matrix_t R;
  s21_create_matrix(3, 3, &R);
  int res;
  res = s21_inverse_matrix(NULL, &R);
  ck_assert_int_eq(1, res);
  s21_remove_matrix(&R);
}
END_TEST
START_TEST(inverse_matrix_3) {
  matrix_t R;
  s21_create_matrix(3, 3, &R);
  int res;
  res = s21_inverse_matrix(&R, NULL);
  ck_assert_int_eq(1, res);
  s21_remove_matrix(&R);
}
END_TEST

START_TEST(inverse_matrix_4) {
  matrix_t A, R, check;
  int res;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &check);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;

  check.matrix[0][0] = 1;
  check.matrix[0][1] = -1;
  check.matrix[0][2] = 1;
  check.matrix[1][0] = -38;
  check.matrix[1][1] = 41;
  check.matrix[1][2] = -34;
  check.matrix[2][0] = 27;
  check.matrix[2][1] = -29;
  check.matrix[2][2] = 24;

  res = s21_inverse_matrix(&A, &R);
  ck_assert_int_eq(0, res);

  res = s21_eq_matrix(&R, &check);
  ck_assert_int_eq(1, res);

  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
  s21_remove_matrix(&check);
}
END_TEST

Suite *suite_s21_inverse_matrix() {
  Suite *s = suite_create("s21_inverse_matrix");
  TCase *tc = tcase_create("s21_inverse_matrix");

  tcase_add_test(tc, inverse_matrix_1);
  tcase_add_test(tc, inverse_matrix_2);
  tcase_add_test(tc, inverse_matrix_3);
  tcase_add_test(tc, inverse_matrix_4);

  suite_add_tcase(s, tc);
  return s;
}
