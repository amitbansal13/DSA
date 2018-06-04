#ifndef SORT_H
#define SORT_H
#include "stack.h"
typedef struct employee
{
    char name[11];
    long long int empID;
}employee;

void qs(employee arr[],int lo,int hi,int S);
int pivot(employee arr[],int lo,int hi,int p);
int partition(employee arr[],int lo,int hi);
void swap(employee *a,employee *b);
void insertionSort(employee arr[],int lo,int hi);
#endif
