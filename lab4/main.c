#include "main.h"

int main()
{
	int i=0;
	credit *arr;
	struct timeval t1,t2;	
	int k=read(&arr,"100");
	unsigned int g=&k;
	gettimeofday(&t1,NULL);
	unsigned int l=insertionSort(arr,k);
	gettimeofday(&t2,NULL);
	printf("%u\n\n",l-g);
	double time;
	time=(t2.tv_sec -t1.tv_sec)*1000000+(t2.tv_usec-t1.tv_usec);
	printf("%lf\n",time);
}

