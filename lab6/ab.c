#include <stdio.h>
int partition(int arr[],int lo,int hi,int p)
{
    int lt=lo-1;
    int rt=hi+1
    int k=arr[p];
    while(1)
    {
		do
		{
		    ++lt;
		}while(arr[lt]<k);
		do
		{
		    --rt;
		}while(arr[rt]>k);
		print(arr,hi-lo+1);
		if(lt>=rt)
			return rt;
		
    	swap(arr+lt,arr+rt);
    }
}

void print(int arr[],int size)
{
	int i;
	for(i=0;i<size;i++)
	printf("%d ",arr[i]);
	printf("\n");
}
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
unsigned int sum(int n)
{
	if(n==0)
	{
		unsigned int k=&n;
		return k;
	}
	unsigned int k=sum(n-1);
	return k;
}
int main()
{
	int n;
	unsigned int a=&n;
	unsigned int b=sum(5);
	 
	int arr[]={4,5,2,1,3,8,10};
	partition(arr,0,6,4);
}
