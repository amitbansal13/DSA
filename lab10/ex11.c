#include "ex11.h"
void dfs(Graph g,Vertex V)
{	
	
}
void bfs(Graph g,Vertex V)
{
	 
}
int degree(Graph G,Vertex V)
{
	int count=0;
	int n=G->num,i;
	int index=V->index;
	int **arr=G->arr;
	for(i=0;i<n;i++)
	{
		if(i==index)continue;
		if(arr[i][index]==1)count++;
	}
	for(i=0;i<n;i++)
		if(arr[index][i]==1)count++;
	return count;
}
Graph addEdge(Graph G,Vertex v,Vertex vAdg)
{
	int **arr=G->arr;
	int i=v->index,j=vAdg->index;
	arr[i][j]=1;
	return G;
}
Enumeration getAdjacent(Graph G,Vertex V)
{
	Enumeration e=(Enumeration)malloc(sizeof(struct enumeration));
	int *arr=G->arr[V->index];
	int i=0,n=g->num;
	for(i=0;i<n;i++)if(arr[i]==1)e=add(e,new());
}
Graph createGraph(int numV)
{
	Graph g=(Graph)malloc(sizeof(struct graph));
	g->arr=(int**)malloc(numV*sizeof(int*));
	int i=0;
	while(i!=numV)
	{
		g->arr[i]=(int*)malloc(sizeof(int)*numV);
		int j=0;
		for(j=0;j<numV;j++)
			g->arr[i][j]=0;
		i++;
	}
	g->list=(Vertex)malloc(sizeof(struct vertex)*numV);
	for(i=0;i<numV;i++)
	{
		g->list[i].index=i;
		g->list[i].visited=0;
	}
	g->num=numV;
	return g;
}
void print(Graph g){

	for(int i=0;i<g->num;i++)
	{
		for(int j=0;j<g->num;j++)
			printf("%d ",g->arr[i][j]);
		printf("\n");
	}
}

