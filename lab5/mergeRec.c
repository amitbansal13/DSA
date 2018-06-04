#include "merge.h"
void mergeSort(Element arr[],int size)
{
	if(size>1)
	{
		int mid=size/2;
		Element l1[mid];
		Element l2[size-mid];
		int i=0;
		int k=0;
		for(i=0;i<mid;i++)
		l1[i]=arr[k++];
		for(i=mid;i<size;i++)
		l2[i-mid]=arr[k++];
		mergeSort(l1,mid);
		mergeSort(l2,size-mid);
		merge(l1,mid,l2,size-mid,arr);
	}
}
void merge(Element Ls1[],int sz1,Element Ls2[],int sz2,Element Ls[])
{
	int i=0,j=0,k=0;
	while(i<sz1 && j<sz2)
	{
		if(Ls1[i].cgpa<Ls2[j].cgpa)
			Ls[k++]=Ls1[i++];
		else
			Ls[k++]=Ls2[j++];
	}
	while(i<sz1)
	Ls[k++]=Ls1[i++];
	while(j<sz2)
	Ls[k++]=Ls2[j++];
}
