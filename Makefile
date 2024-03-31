all: main

main: Lab4.c
	gcc -Wall -Werror -o lab4 Lab4.c -lm

rm: main
	rm lab3