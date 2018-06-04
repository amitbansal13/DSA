#ifndef MERGE_H
#define MERGE_H
#include <stdio.h>
#include <stdlib.h>
#define min(x,y) x<y?x:y
struct Element
{
	char s[11];
	float cgpa;
};
typedef struct Element Element;
void mergeSort(Element arr[],int size);
void merge(Element Ls1[],int sz1,Element Ls2[],int sz2,Element Ls[]);//has to be included if we have it in our mergeIter.c
void readRecords(FILE *fp,int k);
void mergeFiles(FILE *fp1,FILE *fp2,char s[]);
void mergeSortF(FILE *fp,int M,int k);
#endif
