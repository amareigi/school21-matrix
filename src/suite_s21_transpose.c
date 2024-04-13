#include "matrix_suitecases.h"

START_TEST(transpose_1) {
  matrix_t A, R, check;
  int res;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &check);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;

  check.matrix[0][0] = 1;
  check.matrix[0][1] = 3;
  check.matrix[1][0] = 2;
  check.matrix[1][1] = 4;
  res = s21_transpose(&A, &R);
  ck_assert_int_eq(0, res);

  res = s21_eq_matrix(&R, &check);
  ck_assert_int_eq(1, res);

  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
  s21_remove_matrix(&check);
}
END_TEST
START_TEST(transpose_2) {
  matrix_t R;
  int res;
  res = s21_transpose(NULL, &R);
  ck_assert_int_eq(1, res);
}
END_TEST
START_TEST(transpose_3) {
  matrix_t B;
  int res;
  s21_create_matrix(2, 2, &B);

  res = s21_transpose(&B, NULL);
  ck_assert_int_eq(1, res);

  s21_remove_matrix(&B);
}
END_TEST

Suite *suite_s21_transpose() {
  Suite *s = suite_create("s21_transpose");
  TCase *tc = tcase_create("s21_transpose");

  tcase_add_test(tc, transpose_1);
  tcase_add_test(tc, transpose_2);
  tcase_add_test(tc, transpose_3);

  suite_add_tcase(s, tc);
  return s;
}
