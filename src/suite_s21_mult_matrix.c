#include "matrix_suitecases.h"

START_TEST(mult_matrix_1) {
  matrix_t A, B, R, check;
  int res;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  s21_create_matrix(2, 2, &check);

  fill_matrix(&A);
  fill_matrix(&B);

  check.matrix[0][0] = 1;
  check.matrix[0][1] = 2;
  check.matrix[1][0] = 2;
  check.matrix[1][1] = 5;
  res = s21_mult_matrix(&A, &B, &R);
  ck_assert_int_eq(0, res);

  res = s21_eq_matrix(&R, &check);
  ck_assert_int_eq(1, res);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
  s21_remove_matrix(&check);
}
END_TEST
START_TEST(mult_matrix_2) {
  matrix_t B, R, check;
  int res;
  s21_create_matrix(2, 2, &B);
  s21_create_matrix(2, 2, &check);

  res = s21_mult_matrix(NULL, &B, &R);
  ck_assert_int_eq(1, res);

  s21_remove_matrix(&B);
  s21_remove_matrix(&check);
}
END_TEST
START_TEST(mult_matrix_3) {
  matrix_t B, R, check;
  int res;
  s21_create_matrix(2, 2, &B);
  s21_create_matrix(2, 2, &check);

  res = s21_mult_matrix(&B, NULL, &R);
  ck_assert_int_eq(1, res);

  s21_remove_matrix(&B);
  s21_remove_matrix(&check);
}
END_TEST
START_TEST(mult_matrix_4) {
  matrix_t B, check;
  int res;
  s21_create_matrix(2, 2, &B);
  s21_create_matrix(2, 2, &check);

  res = s21_mult_matrix(&B, &B, NULL);
  ck_assert_int_eq(1, res);

  s21_remove_matrix(&B);
  s21_remove_matrix(&check);
}
END_TEST
START_TEST(mult_matrix_5) {
  matrix_t A, B, R;
  int res;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(3, 3, &B);

  fill_matrix(&A);
  fill_matrix(&B);

  res = s21_mult_matrix(&A, &B, &R);
  ck_assert_int_eq(2, res);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST
START_TEST(mult_matrix_6) {
  matrix_t A, B, R, check;
  int res;
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 3, &B);
  s21_create_matrix(3, 3, &check);

  fill_matrix(&A);
  fill_matrix(&B);
  check.matrix[0][0] = 1;
  check.matrix[0][1] = 2;
  check.matrix[0][2] = 3;
  check.matrix[1][0] = 2;
  check.matrix[1][1] = 5;
  check.matrix[1][2] = 8;
  check.matrix[2][0] = 3;
  check.matrix[2][1] = 8;
  check.matrix[2][2] = 13;

  res = s21_mult_matrix(&A, &B, &R);
  ck_assert_int_eq(0, res);

  res = s21_eq_matrix(&R, &check);
  ck_assert_int_eq(1, res);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
  s21_remove_matrix(&check);
}
END_TEST

Suite *suite_s21_mult_matrix() {
  Suite *s = suite_create("s21_mult_matrix");
  TCase *tc = tcase_create("s21_mult_matrix");

  tcase_add_test(tc, mult_matrix_1);
  tcase_add_test(tc, mult_matrix_2);
  tcase_add_test(tc, mult_matrix_3);
  tcase_add_test(tc, mult_matrix_4);
  tcase_add_test(tc, mult_matrix_5);
  tcase_add_test(tc, mult_matrix_6);

  suite_add_tcase(s, tc);
  return s;
}
