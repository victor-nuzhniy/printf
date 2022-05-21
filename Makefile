my_printf: main.c my_printf.c
	gcc -Wall -Wextra -Werror -c main.c -o main.o
	gcc -Wall -Wextra -Werror -c my_printf.c -o my_printf.o
	gcc -Wall -Wextra -Werror main.o my_printf.o -o my_printf