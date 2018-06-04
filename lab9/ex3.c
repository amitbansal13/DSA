#include "ex3.h"
curr set()
{
	curr c=(curr)malloc(sizeof(struct currentSet));
	c->count=0;
	c->head=NULL;
	c->tail=NULL;
	return c;
}
void dft(Tree t)
{
	printf("%d\n",t->value);
	curr c=set();
	addMoreNodes(c,t->it);
	while(c->count!=0)
	{
		Element e=selectNextNode(c);
		dft(e->t);
		free(e);
	}
	free(c);
}
void bft(Tree t)
{
	printf("\n\n\nBFT\n\n\n");
	printf("%d\n",t->value);
	curr c=set();
	addMoreNodes(c,t->it);
	while(c->count!=0)
	{
		Element e=selectNextNode(c);
		printf("%d\n",e->t->value);
		addMoreNodes(c,e->t->it);
		free(e);
	}
	free(c);
}
Iterator identifyMoreNodes(curr c)
{	
	if(c->head && c->head->t)
		return c->head->t->it;
	return NULL;
}
void addMoreNodes(curr c,Iterator i)
{
	if(i==NULL)return;
	while(hasMoreElements(i))
	{
		Element temp=getNextElement(i);
		if(c->head==NULL)
		{
			c->head=newElement(temp->t);
			c->tail=c->head;
		}
		else
		{
			Element e=newElement(temp->t);
			c->tail->next=e;
			c->tail=e;
		}
		c->count++;
	}
}
Element selectNextNode(curr c)
{
	if(c->count==0)return NULL;
	Element temp=c->head;
	c->head=c->head->next;
	c->count--;
	if(c->head==NULL)c->tail=NULL;
	return temp;
}
Element newElement(Tree t)
{
	Element e=(Element)malloc(sizeof(Element));
	e->t=t;
	e->next=NULL;
	return e;
}
