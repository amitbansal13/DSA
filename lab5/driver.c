#include "merge.h"
#include <string.h>
int main()
{
	//Element* arr =malloc(sizeof(Element)*10);
	FILE* fpo=fopen("10240.txt","r");
	readRecords(fpo,256);
	char s1[12];
	char s2[12];
	char s[12];
	int j=0;
	int n=40;
	int temp=n+1;
	sprintf(s,"%d.txt",temp);
	sprintf(s1,"%d.txt",1);
	sprintf(s2,"%d.txt",2);		
	FILE *fp1=fopen(s1,"r");
	FILE *fp2=fopen(s2,"r");
	mergeFiles(fp1,fp2,s);
	remove(s1);
	remove(s2);
	for(j=3;j<=n;j++)
	{
		sprintf(s1,"%d.txt",j);
		sprintf(s2,"%d.txt",temp);
		sprintf(s,"%d.txt",temp+1);
		printf("%s %s %s",s1,s2,s);		
		FILE *fp1=fopen(s1,"r");
		FILE *fp2=fopen(s2,"r");
		mergeFiles(fp1,fp2,s);
		remove(s1);
		remove(s2);
		temp++;
		
	}
	rename(s,"output.txt");
}
/*int k=0;
	int def=10;
	while(fscanf(fp,"%[^,],%f\n",arr[k].s,&(arr[k].cgpa))!=-1 && k<10)
	{
		if(k==def-1)
		{
			def+=10;
			arr=(Element*)realloc(arr,def*sizeof(Element));	
		}
		k++;
		
	}
	int i=0;
	mergeSort(arr,k);
	for(i=0;i<10;i++)
	printf("%s,%f\n",arr[i].s,arr[i].cgpa);*/
	

