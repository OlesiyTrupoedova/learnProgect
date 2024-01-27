CC = gcc
CFLAGS := -Wall -Werror -Wextra -std=c11
LDFLAGS := -lcheck

all: s21_math.a

test: ./tests/test.o s21_math.a
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $?
	./test

./tests/test.c:
	checkmk tests/test_math.ts > tests/test.c

./tests/test.o: ./tests/test.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c -o $@ $?

s21_math.a: ./s21_math/s21_math.o
	ar rcs $@ $^

gcov_report: CFLAGS += -fprofile-arcs -ftest-coverage
gcov_report: LDFLAGS += -lgcov
gcov_report: clean s21_math.a test
	./test
	lcov --exclude "math.h" --exclude "test_math.ts" --directory . --capture --output-file ./app.info
	genhtml --ignore-errors unmapped ./app.info -o ./gcov_report
	open ./gcov_report/index.html

rebuild: clean all

clean:
	find . -name *.o -delete
	find . -name *.a -delete
	find . -name *.gcda -delete
	find . -name *.gcno -delete
	rm -f test
	rm -f app.info
	rm -rf gcov_report
