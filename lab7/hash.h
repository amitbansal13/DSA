#ifndef HASH_H
#define HASH_H
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
typedef struct file
{
	char **r;
	int size;
}file;
typedef struct record* link;
struct record
{
    int index;
    //char str[70];
    int count;
    link next;
};
struct hash
{
    int elementCount;
    int insertionCost;
    int queryingCost;
    int tableSize;
    link *chains;
};
typedef struct hash *Table;
file* read(char *name);
int hashFunction(char s[],long long int  baseNumber,int tableSize);
int colCount(char *s[],int size,long long baseNumber,int tableSize);
void profile(char *s[],int size);

//Ex 2
int insertAll(Table t,char *s[],int size);
Table insert(Table t,char *a[],int j);
Table create();
link lookup(Table t,char arr[],char *a[]);
int lookupAll(Table t,char *arr[],int size,float m);
int hf(char s[]);
link newNode(int index);
//Excercise 3
float profiling(Table t,char *book[],int size);
void cleanup(Table t,char **arr,int size);
#endif
