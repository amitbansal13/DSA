#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node* node;
struct Node
{
	int data;
	node next;
};
typedef struct list* List;
struct list
{
 	node head;
};
int findCycle(List l);
node newNode(int data);
List add(List l,node a);
List createList(int N);
List createCycle(List l);
void print(List l);
List makeCycle(List ls);
void* myalloc(int size,int count);
void myfree(void* temp,int size,int count);
