#include "merge.h"
void mergeSort(Element arr[],int size)//iterative procedure
{
	int i=0,j;
	for(i=1;i<size;i*=2)
	{
		for(j=0;j<size;j+=2*i)
		{
			int s2=j+i;//starting of the second array to be merged
			int e2=j+2*i-1;
			
			int e=min(e2,size-1);
			Element* a=(Element*)malloc(sizeof(Element)*(e-s2+1+i));
			merge(arr+j,i,arr+s2,e-s2+1,a);//important to note to get the starting of the second array
			int k=0;
			for(k=j;k<e-s2+1+i+j;k++)// starting from j bcoz we have to copy from jth element in arr 
			arr[k]=a[k-j];
			free(a);
		}	
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
