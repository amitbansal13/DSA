cycle.o: cycle.c cycle.h
	gcc -c cycle.c
test1: test.c cycle1.c cycle.h cycle.o
	gcc -c test.c cycle1.c
	gcc test.o cycle1.o cycle.o
test2: test.c cycle2.c cycle.h cycle.o
	gcc -c test.c cycle2.c
	gcc test.o cycle2.o cycle.o
