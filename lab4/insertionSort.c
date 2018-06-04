#include "main.h"
unsigned int insertionSort(credit *arr,int size)
{
	if(size==1)
	{
		unsigned int a=&size;	
		return a;
	}
	unsigned int k=insertionSort(arr,size-1);
	insertInOrder(arr,size-1,arr[size-1]);
	return k;
}
void insertInOrder(credit *arr,int size,credit key)
{
	int i=0;
	while(i<size && key.num>arr[i].num)
		i++;
	int j=0;
	for(j=size-1;j>=i;j--)
		arr[j+1]=arr[j];
	arr[i]=key;
	
}
