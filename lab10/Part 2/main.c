#include"ex1.h"

int main()
{
	int V = 5;
    Graph graph = createGraph(V);
    Vertex a,b,c,d,e;
	a=new(0);
    b=new(1);
    c=new(2);
    d=new(3);
    e=new(4);
    graph=addEdge(graph, a, b);
    graph=addEdge(graph,a,e);
    graph=addEdge(graph,b,c);
    graph=addEdge(graph, b, d);
    graph=addEdge(graph, b, e);
    graph=addEdge(graph, c, d);
    graph=addEdge(graph, d, e);
    print(graph);
    bfs(graph,a);
    zero(graph);
    dfs(graph,a);
    return 0;
}
