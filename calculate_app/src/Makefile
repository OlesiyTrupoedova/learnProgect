.PHONY: all install uninstall test clean

CC = gcc
CFLAGS = -Werror -Wall -Wextra -std=c11
CLANG := -n

ifeq ($(shell uname -s),Linux)
	LDFLAGS = -lcheck -pthread -lrt -lm -lsubunit
else
	LDFLAGS = -lcheck
endif

TEST_CALC = $(wildcard logic/tests/*.c)
TEST_OBJ_CALC  = $(TEST_CALC:.c=.o)

CALC_SRC = $(wildcard logic/*.c)
CALC_OBJS = $(CALC_SRC:.c=.o)

all: install

install: uninstall
	mkdir build
	cd build && qmake ../Calculator && make
	cd build && open Calculator.app

uninstall: clean
	rm -rf build

test: $(CALC_OBJS) $(TEST_OBJ_CALC) 
	$(CC) -std=c11 $(TEST_OBJ_CALC) $(CALC_OBJS) $(CFLAGS) $(LDFLAGS) -o test 
	./test

clean:
	rm -rf test
	rm -rf ./logic/*.o ./logic/*.gcno ./logic/*.gcda
	rm -rf ./logic/tests/*.o ./logic/tests/*.gcno ./logic/tests/*.gcda
	rm -rf ./gcov_report
	rm -rf app.info
	rm -rf calculator.html

gcov_report: CFLAGS += -fprofile-arcs -ftest-coverage
gcov_report: LDFLAGS += --coverage
gcov_report: clean test
	mkdir gcov_report
	lcov --directory . --capture --output-file ./app.info
	lcov --remove ./app.info '*/tests/*' -o ./app.info
	genhtml ./app.info -o ./gcov_report
	open ./gcov_report/index.html


TEXI2HTML=makeinfo --no-split --html

dvi: 
	$(TEXI2HTML) ./instructions.texi
	open calculator.html

dist: uninstall install
	tar cvzf Calculator.tgz build/

clang-format:
	clang-format --style=Google $(CLANG) logic/*.c logic/*.h
	clang-format --style=Google $(CLANG) logic/tests/*.c logic/tests/*.h

