#include "GraphAdjList.h"
int main(void){
	FILE* f = fopen("graph0.txt", "r");
	Graph g = readFile(f);
	if(g == NULL){printf("ERROR");}
	for(int i = 0; i < 8; i++){
		Vertex v = searchVertexbyIndex(g->v, i);
		printf("Vertex%d :\t%d\t%d\t%d\t%d\n", i, v->vindex, v->data, indegree(g, v), outdegree(g, v));
	}
	Vertex currr = g->v->head;
	/*int j = 0;
	while(currr != NULL){
		printf("Vertex%d :\t%d\t%d\t%d\t%d\n", j, currr->vindex, currr->data, indegree(g, currr), outdegree(g, currr));
		currr = currr->next;
		j++;
	}*/
	/*Label** arr = BFS(g, searchVertex(g->v, 0));
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			//if(g->adj[i][j] == 1){
				printf("%d\t%d\t%d\n", i, j, arr[i][j]);
			//}
	        }
	}*/
	Queue q = topsort(g);
	if(q == NULL){printf("No directed cycle");}
	Vertex curr = q->head;
	int i = 1;
	while(curr != NULL){
		printf("%d\t%d\n", i, curr->data);
		i++;
		curr = curr->next;
	}
	fclose(f);
}
