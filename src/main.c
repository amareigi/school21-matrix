#include "matrix_suitecases.h"
#include "s21_matrix.h"

int main(void) {
  Suite *cases[] = {suite_s21_create_matrix(),  suite_s21_remove_matrix(),
                    suite_s21_eq_matrix(),      suite_s21_sum_matrix(),
                    suite_s21_sub_matrix(),     suite_s21_mult_matrix(),
                    suite_s21_mult_number(),    suite_s21_transpose(),
                    suite_s21_determinant(),    suite_s21_calc_complements(),
                    suite_s21_inverse_matrix(), NULL};

  for (Suite **current_testcase = cases; *current_testcase != NULL;
       current_testcase++) {
    run_testcase(*current_testcase);
  }
  return 0;
}

void run_testcase(Suite *testcase) {
  SRunner *sr = srunner_create(testcase);
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);
  srunner_free(sr);
}

void fill_matrix(matrix_t *mat) {
  for (int i = 0; i < mat->rows; i++)
    for (int j = 0; j < mat->columns; j++) mat->matrix[i][j] = i + j;
}
