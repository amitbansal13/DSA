compile: main.o measureTimeAndSpace.o readRecords.o insertionSort.o
	gcc main.o measureTimeAndSpace.o readRecords.o insertionSort.o -o exe
main.o: main.c readRecords.c insertionSort.c measureTimeAndSpace.c main.h
	gcc -c main.c
measureTimeAndSpace.o: measureTimeAndSpace.c readRecords.c main.h
	gcc -c measureTimeAndSpace.c
readRecords.o: readRecords.c main.h
	gcc -c readRecords.c
insertionSort.o: insertionSort.c main.h
	gcc -c insertionSort.c
