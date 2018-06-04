#include "cycle.h"
#include <sys/time.h>
int globcnt=0;
int main()
{
	struct timeval t1,t2;

	int i;
	srand(time(NULL));
	gettimeofday(&t1,NULL);
	int n=10;
	List l=createList(n);
	gettimeofday(&t2,NULL);
	double time=(t2.tv_sec -t1.tv_sec)*1000.0;
	time+=(t2.tv_usec-t1.tv_usec)/1000.0;
	l=createCycle(l);
	print(l);
	makeCycle(l);
	print(l);
	printf("The time taken for n=%d is %lf ms.\nThe space taken is %d\n",n,time,globcnt);
	return 0;

}
void* myalloc(int size,int count)
{
	globcnt+=size*count;
	return malloc(size*count);
}
void myfree(void* temp,int size,int count)
{
	globcnt-=size*count;
	free(temp);
}
