.PHONY: clean gcov_report rebuild test test_compile check valgrind clnag-format
CC = gcc
CFLAGS := -std=c11 -Wall -Wextra -Werror

TARGET = s21_decimal.a

ifeq ($(shell uname -s),Linux) 
	LDFLAGS = -pthread -lcheck_pic -pthread -lrt -lm -lsubunit
else  
	LDFLAGS = -lcheck 
endif

TEST_DECIMAL  = $(wildcard tests/*.c)
TEST_OBJ_DECIMAL  = $(TEST_DECIMAL:.c=.o)

DECIMAL_SRC = $(wildcard *.c)
DECIMAL_OBJS =   $(DECIMAL_SRC:.c=.o)

rebuild: clean all

all: $(TARGET)

$(TARGET): $(DECIMAL_OBJS)
	ar rcs $@ $^ $(DECIMAL_OBJS)

gcov_report: CFLAGS += -fprofile-arcs -ftest-coverage
gcov_report: LDFLAGS += -lgcov --coverage
gcov_report: $(TARGET) test
	lcov --directory . --capture --output-file ./app.info
	genhtml ./app.info -o ./gcov_report
	open ./gcov_report/index.html

test_compile: $(TEST_OBJ_DECIMAL) $(TARGET)
	$(CC) -std=c11 $(TEST_OBJ_DECIMAL) $(LDFLAGS) $(TARGET) -o tests/test

test: $(TEST_OBJ_DECIMAL) $(TARGET) 
	$(CC) -std=c11 $(TEST_OBJ_DECIMAL) $(LDFLAGS) $(TARGET) -o tests/$@
	./tests/test

test%.o: test%.c
	$(CC) -std=c11 -c $< $(LDFLAGS) -o $@

check: valgrind clang-format

valgrind: test_compile
	CK_FORK=no valgrind --tool=memcheck --leak-check=yes tests/test

clang-format:
	clang-format --style=Google -n *.c *.h
	clang-format --style=Google -n tests/*.c tests/*.h

clean:
	rm -rf gcov_report
	rm -f $(TARGET)
	rm -rf *.o *.gcda *.gcno app.info
	rm -rf obj/*.o tests/obj/*.o tests/*.o
	rm tests/test

