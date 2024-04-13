#include "matrix_suitecases.h"

START_TEST(sum_matrix_1) {
  matrix_t A, B, R, check;
  int res;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  s21_create_matrix(2, 2, &check);

  fill_matrix(&A);
  fill_matrix(&B);

  check.matrix[0][0] = 0;
  check.matrix[0][1] = 2;
  check.matrix[1][0] = 2;
  check.matrix[1][1] = 4;
  res = s21_sum_matrix(&A, &B, &R);
  ck_assert_int_eq(0, res);

  res = s21_eq_matrix(&R, &check);
  ck_assert_int_eq(1, res);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
  s21_remove_matrix(&check);
}
END_TEST
START_TEST(sum_matrix_2) {
  matrix_t B, R, check;
  int res;
  s21_create_matrix(2, 2, &B);
  s21_create_matrix(2, 2, &check);

  res = s21_sum_matrix(NULL, &B, &R);
  ck_assert_int_eq(1, res);

  s21_remove_matrix(&B);
  s21_remove_matrix(&check);
}
END_TEST
START_TEST(sum_matrix_3) {
  matrix_t B, R, check;
  int res;
  s21_create_matrix(2, 2, &B);
  s21_create_matrix(2, 2, &check);

  res = s21_sum_matrix(&B, NULL, &R);
  ck_assert_int_eq(1, res);

  s21_remove_matrix(&B);
  s21_remove_matrix(&check);
}
END_TEST
START_TEST(sum_matrix_4) {
  matrix_t B, check;
  int res;
  s21_create_matrix(2, 2, &B);
  s21_create_matrix(2, 2, &check);

  res = s21_sum_matrix(&B, &B, NULL);
  ck_assert_int_eq(1, res);

  s21_remove_matrix(&B);
  s21_remove_matrix(&check);
}
END_TEST
START_TEST(sum_matrix_5) {
  matrix_t A, B, R;
  int res;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(3, 3, &B);

  fill_matrix(&A);
  fill_matrix(&B);

  res = s21_sum_matrix(&A, &B, &R);
  ck_assert_int_eq(2, res);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *suite_s21_sum_matrix() {
  Suite *s = suite_create("s21_sum_matrix");
  TCase *tc = tcase_create("s21_sum_matrix");

  tcase_add_test(tc, sum_matrix_1);
  tcase_add_test(tc, sum_matrix_2);
  tcase_add_test(tc, sum_matrix_3);
  tcase_add_test(tc, sum_matrix_4);
  tcase_add_test(tc, sum_matrix_5);

  suite_add_tcase(s, tc);
  return s;
}
