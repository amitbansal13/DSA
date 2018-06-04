#include "sort.h"
void qs(employee arr[],int lo,int hi,int S)
{
    int stack[hi-lo+1];
    int top=-1;
    stack[++top]=lo;
    stack[++top]=hi;
    int l=lo,h=hi;
    while(top>=0)
    {
    	h=stack[top--];
    	l=stack[top--];
    	int p=partition(arr,l,h);
    	if(p-l>S)
    	{
    		//printf("p-l=%d\n",p-l);
    		stack[++top]=l;
    		stack[++top]=p-1;
    	}
    	if(h-p>S)
    	{
    		//printf("h-p=%d\n",h-p);
		stack[++top]=p+1;
		stack[++top]=h;
    	}
    }
    //insertionSort(arr,lo,hi);
}
/*
int partition(employee arr[],int lo,int hi)
{
    int lt=lo-1;
    int rt=hi+1;
    long long int k=arr[lo].empID;
    while(1)
    {
	do
	{
	    ++lt;
	}while(arr[lt].empID<k);
	do
	{
	    --rt;
	}while(arr[rt].empID>=k);
	if(lt>=rt)
		return rt;
    	swap(arr+lt,arr+rt);
    }
}*/
int partition (employee arr[], int l, int h)
{
	employee x = arr[h];
    int i = (l - 1);
 	int j;
    for (j = l; j <= h-1; j++)
    {
        if (arr[j].empID <= x.empID)
        {
            i++;
            swap (&arr[i], &arr[j]);
        }
    }
    swap (&arr[i + 1], &arr[h]);
    return (i + 1);
}
void swap(employee *a,employee *b)
{
    employee temp=*a;
    *a=*b;
    *b=temp;
}
void insertionSort(employee arr[],int lo,int hi)
{
    int i,j;
    for(i=lo;i<hi;i++)
    {
        employee a=arr[i+1];
        j=i;
        while(j>=lo && arr[j].empID>a.empID)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=a;
    }
}

