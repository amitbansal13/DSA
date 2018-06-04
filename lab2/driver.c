#include "multiq.h"
void p(Queue q)
{
	Element temp=q->front;
	while(temp!=NULL)
	{printf("(%d,%d)<-",temp->p,temp->tid);temp=temp->next;}
	printf("NULL\n");

}
void mp(MultiQ q)
{
	int k=0;
	Queue* temp=q->front;
	while(temp!=q->end)
	{
		temp=&(q->q)[k];
		p((q->q)[k]);
		k++;		
	}
	
}
int main()

{
	Element a=newElement(0,1);
	Element b=newElement(0,2);
	Element c=newElement(0,3);
	Element d=newElement(1,4);
	Element e=newElement(1,5);
	Element f=newElement(2,6);
	Element g=newElement(4,6);
	Element h=newElement(5,6);
	MultiQ q=createMQ(6);
	q=addMQ(q,a);
	q=addMQ(q,c);
	q=addMQ(q,d);
	q=addMQ(q,b);
	q=addMQ(q,e);
	q=addMQ(q,f);
	q=addMQ(q,g);
	q=addMQ(q,h);
	mp(q);
	q=delNextMQ(q);
	mp(q);
	Element aa=newElement(0,11);
	Element ab=newElement(0,12);
	Element ac=newElement(0,13);
	Element ad=newElement(2,14);
	Element ae=newElement(1,15);
	Element af=newElement(2,16);
	/*Queue aq=newQ();
	aq=addMQ(aq,aa);
	aq=addMQ(aq,ac);
	aq=addMQ(aq,ad);
	aq=addMQ(aq,ab);
	aq=addMQ(aq,ae);
	aq=addMQ(aq,af);
	*/

	return 0;
}
