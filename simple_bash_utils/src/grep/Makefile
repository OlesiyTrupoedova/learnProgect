CC= gcc
FLAGS= -Wall -Wextra -Werror -std=c11

s21_grep: grep.o parse.o logic.o
	${CC} grep.o parse.o logic.o -o s21_grep
grep.o: grep.c
	${CC} ${FLAGS} grep.c -c grep.c
logic.o: logic.c
	${CC} ${FLAGS} grep.c -c logic.c
parse.o: parse.c
	${CC} ${FLAGS} grep.c -c parse.c
clean:
	rm *.o s21_grep
