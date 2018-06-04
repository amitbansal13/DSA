#ifndef QUE_H
#define QUE_H
#include <stdio.h>
#include <stdlib.h>
typedef struct element* Element;
struct element
{
	int p;
	int tid;
	Element next;
};
typedef struct queue* Queue;
struct queue
{
	Element front;
	Element end;

};

Queue newQ(); // returns an empty Queue
int isEmptyQ(Queue q); // tests whether q is empty
Queue delQ(Queue q); // deletes the element from the front of the Queue;
//returns the modified Queue
Element front(Queue q); // returns the element from the front of the Queue;
Queue addQ(Queue q , Element e); // adds e to the rear of the Queue; returns the modified Queue
int lengthQ(Queue q); // returns the length of the Queue
Element newElement(int p,int tid);
#endif
