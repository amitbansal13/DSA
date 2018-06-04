#include "ex1.h"
void zero(Graph g)
{
	int n=g->num,i;
	for(i=0;i<n;i++)
		g->arr[i].visited=0;
}
void dfs(Graph g,Vertex v)
{
	if(v==NULL)return;
	printf("%d\n",v->index);
	Vertex temp=getAdjacent(g,v).head;
	while(temp!=NULL)
	{
		if(g->arr[temp->index].visited!=1)
		{
			g->arr[temp->index].visited=1;
			dfs(g,temp);
		}
		temp=temp->next;
	}
}
void bfs(Graph g,Vertex v)
{
	Queue q=newQ();
	q=addQ(q,new(v->index));
	while(!isEmptyQ(q))
	{
		Vertex temp=front(q);
		if(g->arr[temp->index].visited!=1)
		{
			printf("Not visited %d\n",temp->index);
			g->arr[temp->index].visited=1;
			Vertex temp1=getAdjacent(g,temp).head;
			while(temp1!=NULL){q=addQ(q,new(temp1->index));temp1=temp1->next;}		
		}
		free(temp);
	}
	printf("End\n\n\n");
}
Vertex new(int i)
{
	Vertex v=(Vertex)malloc(sizeof(struct vertex));
	v->index=i;
	//v->visited=0;
	v->next=NULL;
}
void print(Graph g)
{
	int v;
    for (v = 0; v < g->num; ++v)
    {
        Vertex pCrawl = g->arr[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl)
        {
            printf("-> %d", pCrawl->index);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}
int degree(Graph G,Vertex V)
{
	int count=0;
	List *arr=G->arr;
	Vertex temp=arr[V->index].head;
	while(temp!=NULL)
	{
		count++;
		temp=temp->next;
	}
	int i=0;
	int total=G->num;
	while(i!=total)
	{
		if(i==V->index){i++;continue;}
		Vertex temp=arr[i].head;
		while(temp!=NULL)
		{
			if(temp==V)
			{count++;break;}
			temp=temp->next;
		}
		i++;
	}
	return count;
}
Graph addEdge(Graph G,Vertex v,Vertex v1)
{
/*
as List is a struct now we can't use it as l.head because it is a local
struct and changing it wouldn't change the struct present in Graph g
earlier it was defined as
List l=G->arr[v->index]
So it made l a local struct.
*/
	Vertex vAdg=new(v1->index);
	vAdg->next=G->arr[v->index].head;
	G->arr[v->index].head=vAdg;
	return G;
}
List getAdjacent(Graph G,Vertex V)
{
	//printf("%d\n",V->index);
	return (G->arr)[V->index];
}
Graph createGraph(int numV)
{
	Graph g=(Graph)malloc(sizeof(struct graph));
	g->num=numV;
	g->arr=(List*)malloc(sizeof(List)*numV);
	int i=0;
	while(i!=numV)
	{
		g->arr[i].head=NULL;
		g->arr[i].index=i;
		g->arr[i].visited=0;
		i++;
	}
	return g;
}
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
Element	front(Queue q)
{
	if(isEmptyQ(q))
		return NULL;
	Element temp=q->front;
	q->front=q->front->next;
	//free(temp);
	return temp;
}