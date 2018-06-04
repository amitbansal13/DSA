#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
typedef struct edge* Edge;
typedef struct vertex* Vertex;
typedef struct edgelist* Edgelist;
typedef struct vertexlist* Vertexlist;
typedef struct vertexlist* Enumeration;
typedef struct vertexlist* Queue;
typedef struct graph* Graph;
typedef struct stack* Stack;
struct edge{
	Vertex src;
	Vertex dst;
	Edge next;
};
struct vertex{
	int vindex;
	int data;
	Vertex next;
};
struct edgelist{
	Edge head;
	Edge tail;
};
struct vertexlist{
	Vertex head;
	Vertex tail;
};
struct graph{
	Edgelist e;
	Vertexlist v;
	int num;
};
struct stack{
	Vertex* array;
	int top;
	int maxindex;
};
Stack push(Stack s, Vertex v);
Vertex pop(Stack s);
Stack newStack(int num);

Edge newEdge();
Vertex newVertex(int vindex, int data);
Vertexlist addVertex(Vertexlist v, Vertex v1);
Edgelist addEdge(Edgelist e, Edge e1);
Vertex searchVertex(Vertexlist v, int data);

Enumeration getAdjSrc(Graph g, Vertex v);		
// gets the adjacent vertices for which this vertex is a source 
Enumeration getAdjDst(Graph g, Vertex v);		
// gets the adjacent vertices for which this is the destination
int indegree(Graph g, Vertex v);
int outdegree(Graph g, Vertex v);

Graph readFile(FILE* f);
Queue topsort(Graph g);





