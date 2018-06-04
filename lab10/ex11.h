#include <stdio.h>
#include <stdlib.h>
typedef struct graph *Graph;
typedef struct vertex *Vertex;
typedef struct enumeration	*Enumeration;
struct graph
{
	int num;
	int **arr;
	Vertex list;
};
typedef struct vertex
{
	int index;
	int visited;
};
struct enumeration
{
	Vertex v;
	Enumeration next;
};
void dfs(Graph g,Vertex v);
void bfs(Grapg g,Vertex v);
int degree(Graph G,Vertex V);
Graph addEdge(Graph G,Vertex v,Vertex vAdg);
int* getAdjacent(Graph G,Vertex V);
Graph createGraph(int numV);
void print(Graph g);
