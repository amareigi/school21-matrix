#include "matrix_suitecases.h"

START_TEST(calc_complements_1) {
  matrix_t A, R;
  int res;
  s21_create_matrix(2, 3, &A);

  fill_matrix(&A);

  res = s21_calc_complements(&A, &R);
  ck_assert_int_eq(2, res);

  s21_remove_matrix(&A);
}
END_TEST
START_TEST(calc_complements_2) {
  matrix_t R;
  s21_create_matrix(3, 3, &R);
  int res;
  res = s21_calc_complements(NULL, &R);
  ck_assert_int_eq(1, res);
  s21_remove_matrix(&R);
}
END_TEST
START_TEST(calc_complements_3) {
  matrix_t R;
  s21_create_matrix(3, 3, &R);
  int res;
  res = s21_calc_complements(&R, NULL);
  ck_assert_int_eq(1, res);
  s21_remove_matrix(&R);
}
END_TEST

START_TEST(calc_complements_4) {
  matrix_t A, R, check;
  int res;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &check);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;

  check.matrix[0][0] = 0;
  check.matrix[0][1] = 10;
  check.matrix[0][2] = -20;
  check.matrix[1][0] = 4;
  check.matrix[1][1] = -14;
  check.matrix[1][2] = 8;
  check.matrix[2][0] = -8;
  check.matrix[2][1] = -2;
  check.matrix[2][2] = 4;

  res = s21_calc_complements(&A, &R);
  ck_assert_int_eq(0, res);

  res = s21_eq_matrix(&R, &check);
  ck_assert_int_eq(1, res);

  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
  s21_remove_matrix(&check);
}
END_TEST

Suite *suite_s21_calc_complements() {
  Suite *s = suite_create("s21_calc_complements");
  TCase *tc = tcase_create("s21_calc_complements");

  tcase_add_test(tc, calc_complements_1);
  tcase_add_test(tc, calc_complements_2);
  tcase_add_test(tc, calc_complements_3);
  tcase_add_test(tc, calc_complements_4);

  suite_add_tcase(s, tc);
  return s;
}
