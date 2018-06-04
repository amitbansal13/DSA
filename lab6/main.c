#include "sort.h"
#include <time.h>
int main()
{
    srand(time(NULL));
    employee *arr=(employee*)malloc(sizeof(employee)*1000);
    FILE *fp=fopen("data.txt","r");
    int k=0;
    int def=1000;
    while(fscanf(fp,"%s %lld",arr[k].name,&arr[k].empID)!=-1)
    {
	if(k==def-1)
	{
	    def+=100;
	    arr=(employee*)realloc(arr,sizeof(employee)*def);
	}
	k++;
    }
    printf("%d",k);
    qs(arr,0,k-1,1);
    int i=0;
   printf("\n\nSORTED\n\n");
    for(i=0;i<k;i++)
    printf("%s %lld\n",arr[i].name,arr[i].empID);

}
