CC = gcc
FLAG_C = -c
FLAG_O = -o
ASAN = -g -fsanitize=address
FLAG_COV = --coverage
FLAG_ER = -Wall -Werror -Wextra -std=c11
VALGRIND_FLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes
s21_MATRIX_C = s21_*.c
s21_MATRIX_O = s21_*.o
BASE_C = base_*.c
BASE_O = base_*.o
SUITE_CASES_C = suite_*.c
SUITE_CASES_O = suite_*.o
FLAG_TESTS = -lcheck -lm -lgcov -lsubunit



all: clean gcov_report

s21_matrix.a:
	$(CC) $(FLAG_C) $(FLAG_ER) $(s21_MATRIX_C) $(BASE_C) 
	ar rc s21_matrix.a $(s21_MATRIX_O) $(BASE_O) -lm
	ranlib s21_matrix.a

test: s21_matrix.a
	$(CC) $(FLAG_C) $(FLAG_ER) $(SUITE_CASES_C) main.c
#	$(CC) $(ASAN) $(FLAG_ER) $(FLAG_COV) $(FLAG_O) tests $(s21_MATRIX_C) main.o $(BASE_O) $(SUITE_CASES_O) $(FLAG_TESTS) 
	$(CC) $(FLAG_ER) $(FLAG_COV) $(FLAG_O) tests $(s21_MATRIX_C) main.o $(BASE_O) $(SUITE_CASES_O) $(FLAG_TESTS)
	./tests

valgrind_test: s21_matrix.a
	$(CC) $(FLAG_C) $(FLAG_ER) $(SUITE_CASES_C) main.c -g
	$(CC) -g $(FLAG_ER) $(FLAG_COV) $(FLAG_O) tests $(s21_MATRIX_C) main.o $(BASE_O) $(SUITE_CASES_O) $(FLAG_TESTS)
	valgrind $(VALGRIND_FLAGS) ./tests

gcov_report: test
	gcovr --html-details -o report.html

cpp_check:
	cppcheck --enable=all --force *.h *.c

style_check:
	cp ../materials/linters/.clang-format ./
	clang-format -n *.c
	clang-format -i *.c
	rm -rf .clang-format

clean:
	-rm -rf *.o *.html *.gcda *.gcno *.css *.a *.gcov *.info *.out *.cfg *.txt
	-rm -f tests
	-rm -f report
	find . -type d -name 'tests.dSYM' -exec rm -r {} +
