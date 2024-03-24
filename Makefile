all: main

main: main.c
	gcc -Wall -Werror -o lab1 lab1.c

rm: main
	rm lab1