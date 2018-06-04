#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>
#include <string.h>
typedef enum {false, true} Bool;
typedef enum {unexplored, treee, cross} Label;
typedef struct vertex* Vertex;
typedef struct vertexlist* Vertexlist;
typedef struct adjElement* Adj;
typedef struct enumeration* Enumeration;
typedef struct vertexlist* Queue;
typedef struct element* Element;
typedef struct indexlist* Indexlist;
typedef struct graph* Graph;
typedef struct stack* Stack;
typedef struct vertex vertex;
struct vertex{
	int vindex;
	int data;
	Indexlist Srclist;
	Indexlist Dstlist;
	/*Vertexlist Srclist;
	Vertexlist Dstlist;*/
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
	int index;
	Element next;
};
struct indexlist{
	Element head;
	Element tail;
};
struct graph{
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

Element newElement(int index);
Vertex newVertex(int vindex, int data);
Vertex searchVertex(Vertexlist v, int data);
Vertex searchVertexbyIndex(Vertexlist v, int index);
Vertexlist addVertex(Vertexlist v, Vertex v1);
Indexlist addIndex(Indexlist lst, int index);
Enumeration searchIndexedVertex(Graph g, Indexlist lst);
Enumeration addAdj(Enumeration e, Adj a);

Enumeration getAdjSrc(Graph g, Vertex v);		
// gets the adjacent vertices for which this vertex is a source 
Enumeration getAdjDst(Graph g, Vertex v);		
// gets the adjacent vertices for which this is the destination
int indegree(Graph g, Vertex v);
int outdegree(Graph g, Vertex v);

Graph readFile(FILE* f);
//Label** BFS(Graph g, Vertex v);
Queue topsort(Graph g);
