#include "main.h"
#include <sys/time.h>
double time(credit **arr,const char *s,int t)
{
	struct timeval t1,t2; int j = 0;
	int i,k; int counter=0;
	gettimeofday(&t1,NULL);
	credit *a;
	for (i=0;i<t;i++)
	{	
		printf("Reading for the %dth time\n",++counter);		
		a = *arr;
		k=read(arr,s);
		
		
	}
	gettimeofday(&t2,NULL);
	double time;
	time=(t2.tv_sec -t1.tv_sec)*1000.0+(t2.tv_usec-t1.tv_usec)/1000.0 ;
	return time;
}
