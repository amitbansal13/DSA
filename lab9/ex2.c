#include "ex2.h"
void printTree(Tree t)
{
	if(isEmpty(t))return;
	while(hasMoreElements(t->it))
	{
		Element e=getNextElement(t->it);
		Tree t1=e->t;
		printTree(t1);
		printf("%d\n",t1->value);
	}
}
Tree createNode(int r)
{
	Tree t=(Tree)malloc(sizeof(struct tnode));
	t->value=r;
	//printf("Tree node\n");
	//printf("%d\n",r);
	t->it=NULL;
	return t;
}
Iterator new(int r)
{
	Iterator it=(Iterator)malloc(sizeof(iter));
	it->count=0;
	it->size=r;
	it->head=NULL;
	it->current=NULL;
	return it;
}
Element newE()
{
	Element e=(Element)malloc(sizeof(struct element));
	e->t=createNode(rand());
	e->next=NULL;
}
Iterator add(Iterator i,Element e)
{
	if(i->head==NULL)
	{
		i->head=e;
		i->current=e;
	}
	else
	{
		i->current->next=e;
		i->current=e;
	}
	return i;
}
Iterator makeList(int r)
{
	if(r==0)
		return NULL;
	Iterator it=new(r);
	int i=0;
	for(i=0;i<r;i++)
	{Element e=newE();it=add(it,e);}//printf("%d\n",e->t->value);}
	it->current=NULL;
	return it;
}
int isEmpty(Tree t)
{
	if(t==NULL || hasMoreElements(t->it)==0)
		return 1;
	return 0;
}
Element getRootVal(Tree t)
{
	return t->value;
}
Tree createTree(int n,int h)
{
	Tree t=(Tree)malloc(sizeof(struct tnode));
	t->it=makeList(n);
	if(n==0 || h==maxh)
		return t;
	while(hasMoreElements(t->it))
	{
		int r1=rand()%11;
		Element e=getNextElement(t->it);
		e->t=createTree(r1,h+1);
		if(e->t->it)
			e->t->it->count=0;
	}
	return t;
}
Iterator getChildren(Tree t)
{
	return t->it;
}
