all: main

main: main.c
	gcc -Wall -Werror -o main main.c

rm: main
	rm main