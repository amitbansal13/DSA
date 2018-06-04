#include "cycle.h"

List makeCycle(List ls)
{
	if(findCycle(ls))
	{
	  node hare=ls->head;
	  node tort=ls->head;
	  while(1)
	  {
	    hare=hare->next->next;
	    tort=tort->next;
	    if(hare==tort)
	      break;
	  }
	  tort=tort->next;
	  int count=1;
	  while(hare!=tort)
	  {
	  	tort=tort->next;
	  	count++;
	  }
	  hare=ls->head;
	  tort=ls->head;
	  while(count>0)
	  {
	  	hare=hare->next;
	  	count--;
	  }
	  while(hare!=tort)
	  {
	  	hare=hare->next;
	  	tort=tort->next;
	  }
	  
	  tort=ls->head;
	  while(tort!=hare)
	  {
	  	tort=tort->next;
	  	free(ls->head);
	  	ls->head=tort;
	  }
	return ls;
	}
	node temp=ls->head;
	while(temp->next!=NULL)
	temp=temp->next;
	temp->next=ls->head;
	return ls;

}
void print(List l)
{
int count=0;
	node temp=l->head;
	if(findCycle(l))
	printf("Cyclic\n");
	while(temp!=NULL && count<15)
	{
	printf("%d->",temp->data);
	temp=temp->next;
	count++;
	}
	printf("NULL\n");
}
int size(List l)
{
	int count=0;
	node temp=l->head;
	while(temp!=NULL)
	{
		temp=temp->next;
		count++;
	}
	return count;
}

List createCycle(List l)
{
	int n=rand();
	int s=size(l);
	node temp=l->head;
	while(temp->next!=NULL)
	{
		temp=temp->next;

	}
	if(n%2==0)
	{
		node temp1=l->head;
		n=n%(s)+1;
			while (n>1)
			{
				temp1=temp1->next;
				n--;
			}
			temp->next=temp1;
		
	}
	return l;

}
List createList(int N)
{
	int i;
	List l=(List)myalloc(sizeof(struct list),1);
	for(i=0;i<N;i++)
	{
		int n=rand();
		node a=newNode(n);
		l=add(l,a);
	}
	return l;
}

List add(List l,node a)
{
	node temp=l->head;
	if(temp==NULL)
		l->head=a;
	else
	{
		a->next=l->head;
		l->head=a;
	}
	return l;
}

node newNode(int data)
{
	node temp=(node)myalloc(sizeof(struct Node),1);
	temp->data=data;
	temp->next=NULL;
	return temp;
}

