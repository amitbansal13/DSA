#include "que.h"

Queue newQ()
{
	Queue a= (Queue)malloc(sizeof(struct queue));
	a->front=NULL;
	a->end=NULL;
	return a;
}
int isEmptyQ(Queue q)
{
	if(q->front==NULL)
		return 1;	
	return 0; 
}
Queue delQ(Queue q)
{
	if(isEmptyQ(q))
		return q;
	Element temp=q->front;
	q->front=q->front->next;
	free(temp);
	return q;
}
Element front(Queue q)
{
	return q->front;
}
Queue addQ(Queue q , Element e)
{
	if(q->front==NULL)
	{
		q->front=e;
		q->end=e;
		e->next=NULL;
	}	
	else
	{
	q->end->next=e;
	e->next=NULL;
	q->end=e;	
	}
	return q;
}
int lengthQ(Queue q)
{
	Element temp=q->front;
	int count=0;
	while(temp!=NULL)
	{
		temp=temp->next;
		count++;
	
	}	
	return count;
}
Element newElement(int data,int id)
{
	Element e=(Element)malloc(sizeof(struct element));
	e->p=data;
	e->tid=id;
	e->next=NULL;
	return e;
}
