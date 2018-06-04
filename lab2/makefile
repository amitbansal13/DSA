compile:
	gcc -c -pg driver.c multiq.c que.c
	gcc -pg driver.o multiq.o que.o -o exe
driver.o: multiq.o
	gcc -c driver.c
multiq.o: multiq.c multiq.h
	gcc -c multiq.c
que.o: que.c que.h
	gcc -c que.c

