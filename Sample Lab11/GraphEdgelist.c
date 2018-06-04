#include "GraphEdgelist.h"
Stack push(Stack s, Vertex v){
	if(s == NULL || s->top == maxindex){return s;}
	else{
		s->array[++s->top] = v;
		return s;
	}
}
Vertex pop(Stack s){
	if(s == NULL || s->top == -1){return NULL;}
	else{
		return s->array[s->top--];
	}
}
Stack newStack(int num){
	Stack s = malloc(sizeof(struct satck));
	s->array = malloc(num * sizeof(struct Vertex));
	s->top = -1;
	s->maxindex = num - 1;
	return s;
}


Edge newEdge(){
	Edge e = malloc(sizeof(struct edge));
	e->next = NULL;
	return e;
}
Vertex newVertex(int vindex, int data){
	Vertex v = malloc(sizeof(struct vertex));
	v->vindex = vindex;
	v->data = data;
	v->next = NULL;
	return v;
}
Vertexlist addVertex(Vertexlist v, Vertex v1){
	if(v->head == NULL){
		v->head = v1;
		v->tail = v1;
	}
	else if(v->head != NULL){
		v->tail->next = v1;
		v->tail = v1;
	}
	return v;
}
Edgelist addEdge(Edgelist e, Edge e1){
	if(e->head == NULL){
		e->head = e1;
		e->tail = e1;
	}
	else if(e->head != NULL){
		e->tail->next = e1;
		e->tail = e1;
	}
	return e;
}
Vertex searchVertex(Vertexlist v, int data){
	Vertex curr = v->head;
	while(curr != NULL){
		if(curr->data == data){return curr;}
		else{curr = curr->next;}
	}
	return NULL;
}


Enumeration getAdjSrc(Graph g, Vertex v){
	Enumeration e = malloc(sizeof(struct vertexlist));
	e->head = NULL;
	e->tail = NULL;
	Edge curr = g->e->head;
	while(curr != NULL){
		if(curr->src == v){
			add = newVertex(curr->dst->vindex, curr->dst->data);
			e = addVertex(e, add);
		}
	}
	return e;
}
Enumeration getAdjDst(Graph g, Vertex v){
	Enumeration e = malloc(sizeof(struct vertexlist));
	e->head = NULL;
	e->tail = NULL;
	Edge curr = g->e->head;
	while(curr != NULL){
		if(curr->dst == v){
			add = newVertex(curr->src->vindex, curr->src->data);
			e = addVertex(e, add);
		}
	}
	return e;
}
int indegree(Graph g, Vertex v){
	Enumeration e = getAdjDst(g, v);
	Vertex curr = e->head;
	int indegree = 0;
	while(curr != NULL){
		curr = curr->next;
		++indegree;
	}
	return indegree;
}
int outdegree(Graph g, Vertex v){
	Enumeration e = getAdjSrc(g, v);
	Vertex curr = e->head;
	int outdegree = 0;
	while(curr != NULL){
		curr = curr->next;
		++outdegree;
	}
	return outdegree;
}


Graph readFile(FILE* f){
	int dat1, dat2;
	Vertex v1, v2;
	int count = 0;
	Vertexlist v = malloc(sizeof(struct vertexlist));
	v->head = v->tail = NULL;
	Edgelist e = malloc(sizeof(struct edgelist));
	e->head = e->tail = NULL;
	while(fscanf(f, "%d %d\n", &dat1, &dat2) == 2){
		Edge curr = newEdge();
		v1 = searchVertex(v, dat1);
		v2 = searchVertex(v, dat2);
		if(v1 == NULL){
			v1 = newVertex(count, dat1);
			v = addVertex(v, v1);
			curr->src = v1;
			count++;
		}
		else{
			curr->src = v1;
		}
		if(v2 == NULL){
			v2 = newVertex(count, dat2);
			v = addVertex(v, v2);
			curr->dst = v2;
			count++;
		}
		else{
			curr->dst = v2;
		}
		e = addEdge(e, curr);
	}
	Graph g = malloc(sizeof(struct graph));
	g->e = e;
	g->v = v;
	g->num = count;
	return g;
}
Queue topsort(Graph g){
	Queue topsort(Graph g){
	Queue q = malloc(sizeof(struct vertexlist));
	int incounter[num];
	q->head = NULL;
	q->tail = NULL;
	Stack s = newStack(g->num);
	Vertex curr = g->v->head;
	Vertex add, crawl;
	Enumeration adj;
	while(curr != NULL){
		incounter[curr->vindex] = indegree(curr);
		if(incounter[curr->vindex] == 0){s = push(s, curr);
	}
	while(s->top != -1){
		curr = pop(s);
		add = newVertex(curr->vindex, curr->data);
		q = addVertex(q, add);
		adj = getAdjSrc(g, curr);
		crawl = adj->head;
		while(crawl != NULL){
			--incounter[crawl->vindex];
			if(incounter[crawl->vindex] == 0){s = push(s, crawl);}
			crawl = crawl->next;
		}
	}
	if(s->top == -1){return q;}
	else{return NULL;}
}		
