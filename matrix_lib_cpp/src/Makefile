CFLAGS = -Wall -Werror -Wextra
LDFLAGS = -lstdc++
all: clean s21_matrix_oop.a

s21_matrix_oop.a:
	g++ -c $(CFLAGS) -std=c++17 s21_matrix_oop.cc 
	ar rcs s21_matrix_oop.a s21_matrix_oop.o
	ranlib s21_matrix_oop.a

clean:
	rm -rf *.o *.out s21_matrix_oop.a  test
	rm -rf *.gcda *.gcno report gcov_report.* gcov_report *.info

leaks: test
	leaks -atExit -- ./test

clang:
	clang-format --style=Google -n s21_matrix_oop.cc s21_matrix_oop_test.cc s21_matrix_oop.h

test: clean
	g++ -lgtest $(LDFLAGS)  -std=c++17 s21_matrix_oop.cc s21_matrix_oop_test.cc -o test
	./test


gcov_report: clean
	g++ -std=c++17 s21_matrix_oop.cc s21_matrix_oop_test.cc -o test --coverage -lgtest -fprofile-arcs -ftest-coverage
	./test
	lcov -d ./ --capture --output-file s21_matrix_oop.info --ignore-errors inconsistent
	genhtml s21_matrix_oop.info --ignore-errors inconsistent --output-directory report
	open report/index.html
