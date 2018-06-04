#include "merge.h"
void readRecords(FILE *fp,int k)
{
	Element *arr=(Element*)malloc(sizeof(Element)*k);
	char s[8]="1.txt";
	int a=0;
	int l=2;
	while(fscanf(fp,"%[^,],%f\n",arr[a].s,&(arr[a].cgpa))!=-1)
	{
		if(a==k-1)
		{
			FILE *f=fopen(s,"w");
			int i=0;
			mergeSort(arr,k);
			for(i=0;i<k;i++)
				fprintf(f,"%s,%f\n",arr[i].s,arr[i].cgpa);
			sprintf(s,"%d.txt",l);
			l++;
			a=0;
			fclose(f);
		}
		else
			a++;
	}
	fclose(fp);
	
}
void mergeFiles(FILE *fp1,FILE *fp2,char s[12])
{
	Element a;
	Element b;
	FILE *f=fopen(s,"w");
	int c1,c2;
	c1=fscanf(fp1,"%[^,],%f\n",a.s,&(a.cgpa));
	c2=fscanf(fp2,"%[^,],%f\n",b.s,&(b.cgpa));
	do
	{
		/*fpos_t a1,a2;
		fgetpos(fp1,&a1);
		fgetpos(fp2,&a2);
		The fpos method gets one extra element into the list when it is about to end
		*/
		
		
		
		if(a.cgpa<b.cgpa)
		{
			fprintf(f,"%s,%f\n",a.s,a.cgpa);
		//	fsetpos(fp2,&a2);
			c1=fscanf(fp1,"%[^,],%f\n",a.s,&(a.cgpa));
			
		}	
		else
		{
			fprintf(f,"%s,%f\n",b.s,b.cgpa);
		//	fsetpos(fp1,&a1);
			c2=fscanf(fp2,"%[^,],%f\n",b.s,&(b.cgpa));
		}
	}
	while(c1!=-1 && c2!=-1);
	while(c1!=-1)
	//if we write here directly in while sentinel that fscanf !=-1 we will 
	//get wrong results there will be 1 element left in this case
	{
		c1=fscanf(fp1,"%[^,],%f\n",a.s,&(a.cgpa));
		fprintf(f,"%s,%f\n",a.s,a.cgpa);
	}
	while(c2!=-1)
	{
		c2=fscanf(fp2,"%[^,],%f\n",b.s,&(b.cgpa));
		fprintf(f,"%s,%f\n",b.s,b.cgpa);
	}
	fclose(f);
	fclose(fp1);
	fclose(fp2);
}
/*void mergeSortF(FILE *fp,int M,int k)
{
	int i=0,j;
	
	readRecords(fp,k);
	if(M==k)return;
	char s[7]="03.txt";
	FILE *fp1=fopen("01.txt","r");
	FILE *fp2=fopen("02.txt","r");
	mergeFiles(fp1,fp2);
	int n=M/k;
	for(i=1;i<n;i*=2)
	{
		int j;
	
	}
	

}*/
