SeqListUses.o: SeqListUses.c SeqList.h
	gcc -c SeqListUses.c
SeqList.o: SeqList.c SeqList.h
	gcc -c SeqList.c
driver: SeqList.h driver.c SeqListUses.o SeqList.o
	gcc -c driver.c
	gcc driver.o SeqListUses.o SeqList.o
	
