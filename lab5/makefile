compRecMS: merge.h mergeRec.c
	gcc -c mergeRec.c
runRecMS: merge.h compRecMS files.c
	gcc -c -pg driver.c files.c
	gcc -pg driver.o mergeRec.o files.o
compIterMS: merge.h mergeIter.c 
	gcc -c mergeIter.c
runIterMS: merge.h compIterMS files.c
	gcc -c driver.c files.c
	gcc driver.o mergeIter.o files.o
	
