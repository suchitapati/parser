all:fsm_main

fsm_main:main.o test.o
	gcc main.o test.o -o fsm_main

main.o:main.c main.h
	gcc -c main.c -o main.o

test.o:test.c test.h
	gcc -c test.c -o test.o

test:fsm_main
	./fsm_main test

run:fsm_main
	./fsm_main run
