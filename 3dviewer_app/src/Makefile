.PHONY: all install uninstall test clean

CC = gcc
CFLAGS = -Werror -Wall -Wextra -std=c11
CLANG := -n

ifeq ($(shell uname -s),Linux)
	LDFLAGS = -lcheck -pthread -lrt -lm -lsubunit
else
	LDFLAGS = -lcheck
endif

TEST_CALC = $(wildcard backend/tests/*.c)
TEST_OBJ_CALC  = $(TEST_CALC:.c=.o)

CALC_SRC = $(wildcard backend/*.c)
CALC_OBJS = $(CALC_SRC:.c=.o)

all: install

install: uninstall
	mkdir build
	cd build && qmake ../3DViewer && make
ifeq ($(shell uname -s),Linux)
	cd build && ./3DViewer
else
	cd build && open 3DViewer.app
endif

uninstall: clean
	rm -rf build

test: $(CALC_OBJS) $(TEST_OBJ_CALC) 
	$(CC) -std=c11 $(TEST_OBJ_CALC) $(CALC_OBJS) $(CFLAGS) $(LDFLAGS) -o test 
	./test

clean:
	rm -rf test
	rm -rf ./backend/*.o ./backend/*.gcno ./backend/*.gcda
	rm -rf ./backend/tests/*.o ./backend/tests/*.gcno ./backend/tests/*.gcda
	rm -rf ./gcov_report
	rm -rf app.info
	rm -rf 3DViewer.html

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
	open 3DViewer.html

dist: uninstall install
	tar cvzf 3DViewer.tgz build/

clang:
	clang-format --style=Google $(CLANG) backend/*.c backend/*.h
	clang-format --style=Google $(CLANG) backend/tests/*.c 
	clang-format --style=Google $(CLANG) 3DViewer/*.cpp 3DViewer/*.h
