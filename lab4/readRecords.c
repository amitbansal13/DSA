#include "main.h"

int read(credit **arr,const char *s)
{
	FILE* fp=fopen(s,"r");
	int def=100;
	int k=0;
	*arr=(credit*)malloc(sizeof(credit)*def);
	credit *a=*arr;
	while(fscanf(fp,"\"%lld,%[^,],%[^,],%[^,],%[^\"]\"\n",&a[k].num,a[k].code,a[k].exp,a[k].fname,a[k].lname)!=-1)
	{
		k++;
		if(k==def)
		{
			def+=100;
			*arr=(credit*)realloc(*arr,sizeof(credit)*def);
			a = *arr;
		}
	}
	return k;
}
