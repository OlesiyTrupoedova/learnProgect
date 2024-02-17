make: s21_cat

s21_cat: cat.o parse.o logic.o
	gcc -o s21_cat cat.o parse.o logic.o
cat.o: cat.c
	gcc -Wall -Wextra -Werror -std=c11 -c cat.c
parse.o: parse.c
	gcc -Wall -Wextra -Werror -std=c11 -c parse.c
logic.o: logic.c
	gcc -Wall -Wextra -Werror -std=c11 -c logic.c
clean:
	rm *.o s21_cat

