#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>
#include <string.h>
typedef enum {false, true} Bool;
typedef enum {unexplored, treee, cross} Label;
typedef struct vertex* Vertex;
typedef struct vertexlist* Vertexlist;
//typedef struct vertexlist* Enumeration;
typedef struct vertexlist* Queue;
typedef struct element* Element;
typedef struct indexlist* Indexlist;
typedef struct graph* Graph;
typedef struct stack* Stack;
typedef struct vertex vertex;
typedef struct adjElement* Adj;
typedef struct enumeration* Enumeration;
struct vertex{
	long long vindex;
	long long data;
	Indexlist Srclist;
	Indexlist Dstlist;
	Vertex next;
};
struct enumeration{
	Adj head;
	Adj tail;
};
struct adjElement{
	Vertex v;
	Adj next;
};
struct vertexlist{
	Vertex head;
	Vertex tail;
};
struct element{
	long long index;
	Element next;
};
struct indexlist{
	Element head;
	Element tail;
};
struct graph{
	Vertexlist v;
	long long num;
};
struct stack{
	Vertex* array;
	long long top;
	long long maxindex;
};

Stack push(Stack s, Vertex v);
Vertex pop(Stack s);
Stack newStack(long long num);

Element newElement(long long index);
Vertex newVertex(long long vindex, long long data);
Vertex searchVertex(Vertexlist v, long long data);
Vertex searchVertexbyIndex(Vertexlist v, long long index);
Vertexlist addVertex(Vertexlist v, Vertex v1);
Indexlist addIndex(Indexlist lst, long long index);
Enumeration searchIndexedVertex(Graph g, Indexlist lst);

Enumeration getAdjSrc(Graph g, Vertex v);		
// gets the adjacent vertices for which this vertex is a source 
Enumeration getAdjDst(Graph g, Vertex v);		
// gets the adjacent vertices for which this is the destination
long long indegree(Graph g, Vertex v);
long long outdegree(Graph g, Vertex v);

Graph readFile(FILE* f);
//Label** BFS(Graph g, Vertex v);
Queue topsort(Graph g);
