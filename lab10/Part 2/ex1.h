#include <stdio.h>
#include <stdlib.h>
typedef struct graph *Graph;
typedef struct vertex *Vertex;
typedef struct list List;
typedef Vertex Element;
typedef struct queue* Queue;
struct queue
{
	Element front;
	Element end;
};
struct graph
{
	int num;
	List *arr;
};
struct vertex
{
	char url[2000];
	Vertex next;
};
struct list
{
	int visited;
	Vertex head;
};
void zero(Graph g);
void bfs(Graph g,Vertex V);
void dfs(Graph g,Vertex V);
int degree(Graph G,Vertex V);
Graph addEdge(Graph G,Vertex v,Vertex vAdg);
List getAdjacent(Graph G,Vertex V);
Graph createGraph(int numV);
void print(Graph g);
Vertex new(int i);
Queue newQ();
int isEmptyQ(Queue q);
Queue addQ(Queue q , Element e);
Element front(Queue q);
