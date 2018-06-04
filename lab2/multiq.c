#include "multiq.h"

MultiQ createMQ(int num)
{
	MultiQ mq=(MultiQ)malloc(sizeof(struct mulq));
	mq->q=(Queue*)malloc(num*sizeof(Queue));
	int i;	
	for(i=0;i<num;i++)
	(mq->q)[i]=newQ();
	mq->front=&(mq->q)[0];
	mq->end=&(mq->q)[num-1];
	return mq;

} // creates a list of num Queues, each of which is empty.
MultiQ addMQ(MultiQ mq, Task t)
{
	int p=t->p;
	(mq->q)[p]=addQ((mq->q)[p],t);
	return mq;

} // adds t to the Queue corresponding to
//priority p in mq. Task includes a TaskID tid and a priority p.
Task nextMQ(MultiQ mq)
{
	Queue* temp=mq->front;
	int k=0;
	if(isEmptyQ((mq->q)[0]))
		return NULL;
	int index=0;
	while(temp!=mq->end )
	{
		if(isEmptyQ((mq->q)[k])==0)
		index=k;
		temp=&(mq->q)[k];
		k++;		
	}
	return front((mq->q)[index]);
	
} // returns the front of the non-empty Queue in mq with the highest priority.
MultiQ delNextMQ(MultiQ mq)
{
	Queue* temp=mq->front;
	int k=0;
	int index=0;
	while(temp!=mq->end )
	{
		if(isEmptyQ((mq->q)[k])==0)
		index=k;//it makes index=k whenever it finds a non empty Q
		temp=&(mq->q)[k];
		k++;		
	}
	(mq->q)[index]=delQ((mq->q)[index]);
	return mq;

} // deletes the front of the non-empty Queue in mq with the highest priority; 
//returns the modified MultiQ
int isEmptyMQ(MultiQ mq)
{
	Queue* temp=mq->front;
	int k=0;	
	while(temp!=mq->end)
	{
		temp=&(mq->q)[k];
		if(isEmptyQ((mq->q)[k])!=1)
		return 0;		
		k++;		
	}
	return 1;
}
// tests whether all the Queues in mq are empty
int sizeMQ(MultiQ mq)
{
	int k=0;
	int m=0;
	Queue* temp=mq->front;
	while(temp!=mq->end)
	{
		temp=&(mq->q)[k];
		m+=lengthQ((mq->q)[k]);
		k++;		
	}
	return m;
} // returns the total number of items in the MultiQ
int sizeMQbyPriority(MultiQ mq, Priority p)
{
	return lengthQ((mq->q)[p]);
} //returns the number of items in mq with the priority p.
Queue getQueueFromMQ(MultiQ mq, Priority p)
{
	return (mq->q)[p];
}
 //returns the Queue with priority p.
