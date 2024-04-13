#include "matrix_suitecases.h"

START_TEST(create_matrix_1) {
  matrix_t test_matrix;
  int test_res;
  test_res = s21_create_matrix(10, 10, &test_matrix);
  test_matrix.matrix[0][0] = 1;
  ck_assert_int_eq(0, test_res);
  ck_assert_int_eq(1, test_matrix.matrix[0][0]);
  ck_assert_ptr_nonnull(test_matrix.matrix);
  s21_remove_matrix(&test_matrix);
}
END_TEST
START_TEST(create_matrix_2) {
  matrix_t test_matrix;
  int test_res;
  test_res = s21_create_matrix(0, 10, &test_matrix);
  ck_assert_int_eq(1, test_res);
}
END_TEST
START_TEST(create_matrix_3) {
  matrix_t test_matrix;
  int test_res;
  test_res = s21_create_matrix(10, 0, &test_matrix);
  ck_assert_int_eq(1, test_res);
}
END_TEST
START_TEST(create_matrix_4) {
  int test_res;
  test_res = s21_create_matrix(10, 10, NULL);
  ck_assert_int_eq(1, test_res);
}
END_TEST

Suite *suite_s21_create_matrix() {
  Suite *s = suite_create("s21_create_matrix");
  TCase *tc = tcase_create("s21_create_matrix");

  tcase_add_test(tc, create_matrix_1);
  tcase_add_test(tc, create_matrix_2);
  tcase_add_test(tc, create_matrix_3);
  tcase_add_test(tc, create_matrix_4);

  suite_add_tcase(s, tc);
  return s;
}
