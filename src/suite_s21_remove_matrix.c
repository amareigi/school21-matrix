#include "matrix_suitecases.h"

START_TEST(remove_matrix_1) {
  matrix_t test_matrix;
  s21_create_matrix(10, 10, &test_matrix);
  s21_remove_matrix(&test_matrix);
  ck_assert_ptr_null(test_matrix.matrix);
}
END_TEST
START_TEST(remove_matrix_2) { s21_remove_matrix(NULL); }
END_TEST
START_TEST(remove_matrix_3) {
  matrix_t test_matrix;
  test_matrix.rows = 0;
  test_matrix.columns = 0;
  test_matrix.matrix = NULL;
  s21_remove_matrix(&test_matrix);
}
END_TEST

START_TEST(remove_matrix_4) {
  matrix_t test_matrix;
  test_matrix.rows = 1;
  test_matrix.columns = 0;
  test_matrix.matrix = NULL;
  s21_remove_matrix(&test_matrix);
}
END_TEST

START_TEST(remove_matrix_5) {
  matrix_t test_matrix;
  test_matrix.rows = 0;
  test_matrix.columns = 1;
  test_matrix.matrix = NULL;
  s21_remove_matrix(&test_matrix);
}
END_TEST

Suite *suite_s21_remove_matrix() {
  Suite *s = suite_create("s21_remove_matrix");
  TCase *tc = tcase_create("s21_remove_matrix");

  tcase_add_test(tc, remove_matrix_1);
  tcase_add_test(tc, remove_matrix_2);
  tcase_add_test(tc, remove_matrix_3);
  tcase_add_test(tc, remove_matrix_4);
  tcase_add_test(tc, remove_matrix_5);

  suite_add_tcase(s, tc);

  return s;
}
