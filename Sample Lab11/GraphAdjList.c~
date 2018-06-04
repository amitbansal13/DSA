#include "GraphAdjList.h"
Stack push(Stack s, Vertex v){
	if(s == NULL || s->top == s->maxindex){return s;}
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
	Stack s = malloc(sizeof(struct stack));
	s->array = malloc(num * sizeof(Vertex));
	s->top = -1;
	s->maxindex = num - 1;
	return s;
}


Element newElement(int index){
	Element e = malloc(sizeof(struct element));
	e->index = index;
	e->next = NULL;
	return e;
}
Vertex newVertex(int vindex, int data){
	Vertex v = malloc(sizeof(struct vertex));
	v->vindex = vindex;
	v->data = data;
	v->Srclist = malloc(sizeof(struct indexlist));
	v->Dstlist = malloc(sizeof(struct indexlist));
	/*v->Srclist = malloc(sizeof(struct vertexlist));
	v->Dstlist = malloc(sizeof(struct vertexlist));*/
	v->Srclist->head = NULL;
	v->Srclist->tail = NULL;
	v->Dstlist->head = NULL;
	v->Dstlist->tail = NULL;
	v->next = NULL;
	return v;
}
Vertex searchVertex(Vertexlist v, int data){
	Vertex curr = v->head;
	while(curr != NULL){
		if(curr->data == data){return curr;}
		else{curr = curr->next;}
	}
	return NULL;
}
Vertex searchVertexbyIndex(Vertexlist v, int index){
	Vertex curr = v->head;
	while(curr != NULL){
		if(curr->vindex == index){return curr;}
		else{curr = curr->next;}
	}
	return NULL;
}
Vertexlist addVertex(Vertexlist v, Vertex v1){
	if(v->head == NULL){
		v->head = v->tail = v1;
		return v;
	}
	else if(v->head != NULL){
		v->tail->next = v1;
		v->tail = v1;
		return v;
	}
}
Indexlist addIndex(Indexlist lst, int index){
	Element e = newElement(index);
	if(lst->head == NULL){
		lst->head = lst->tail = e;
		return lst;
	}
	else if(lst->head != NULL){
		lst->tail->next = e;
		lst->tail = e;
		return lst;
	}
}
Enumeration addAdj(Enumeration e, Adj a){
	if(e->head == NULL){
		e->head = e->tail = a;
		return e;
	}
	else if(e->head != NULL){
		e->tail->next = a;
		e->tail = a;
		return e;
	}
}
Enumeration searchIndexedVertex(Graph g, Indexlist lst){
	Element curr = lst->head;
	int index;
	Adj add;
	Vertex current;
	//Enumeration e = malloc(sizeof(struct vertexlist));
	Enumeration e = malloc(sizeof(struct enumeration));	
	e->head = e->tail = NULL;
	while(curr != NULL){
		index = curr->index;
		current = g->v->head;
		while(current != NULL){
			if(current->vindex == index){
				add = malloc(sizeof(struct adjElement));
				add->v = current;
				add->next = NULL;
				e = addAdj(e, add);
				break;
			}
			else{current = current->next;}
		}
		//add = newVertex(current->vindex, current->vindex);
		//e = addVertex(e, add);
		
		curr = curr->next;
	}
	return e;
}	 
			

Enumeration getAdjSrc(Graph g, Vertex v){
	//return v->Srclist;
	/*int vindex = v->vindex;
	Vertex curr = g->v->head;
	while(curr != NULL){
		if(curr->data == v->data){break;}
		else{curr = curr->next;}
	}*/
	if(v == NULL){return NULL;}
	else if(v != NULL){
		Enumeration e = searchIndexedVertex(g, v->Srclist);
		return e;
	}
}
Enumeration getAdjDst(Graph g, Vertex v){
	//return v->Dstlist;
	if(v == NULL){return NULL;}
	else if(v != NULL){
		Enumeration e = searchIndexedVertex(g, v->Dstlist);
		return e;
	}
}
int indegree(Graph g, Vertex v){
	/*Enumeration e = getAdjDst(g, v);
	if(e == NULL){return 0;}
	//Vertex curr = e->head;
	Adj curr = e->head;
	int indegree = 0;
	while(curr != NULL){
		curr = curr->next;
		++indegree;
	}*/
	int indegree = 0;
	Element curr = v->Dstlist->head;
	while(curr != NULL){
		curr = curr->next;
		indegree++;
	}
	return indegree;
}
int outdegree(Graph g, Vertex v){
	/*Enumeration e = getAdjSrc(g, v);
	if(e == NULL){return 0;}
	//Vertex curr = e->head;
	Adj curr = e->head;
	int outdegree = 0;
	while(curr != NULL){
		curr = curr->next;
		++outdegree;
	}*/
	int outdegree = 0;
	Element curr = v->Srclist->head;
	while(curr != NULL){
		curr = curr->next;
		outdegree++;
	}
	return outdegree;
}


Graph readFile(FILE* f){
	Vertexlist v = malloc(sizeof(struct vertexlist));
	v->head = NULL;
	v->tail = NULL;
	Vertex v1, v2;
	int count = 0;
	int dat1, dat2;
	//Vertex add1, add2;
	while(fscanf(f, "%d %d\n", &dat1, &dat2) == 2){
		v1 = searchVertex(v, dat1);
		v2 = searchVertex(v, dat2);
		if(v1 == NULL){
			v1 = newVertex(count, dat1);
			v = addVertex(v, v1);
			count++;
		}
		if(v2 == NULL){
			v2 = newVertex(count, dat2);
			v = addVertex(v, v2);
			count++;
		}
		v1->Srclist = addIndex(v1->Srclist, v2->vindex);
		v2->Dstlist = addIndex(v2->Dstlist, v1->vindex);
		/*add1 = newVertex(v1->vindex, v1->data);
		add2 = newVertex(v2->vindex, v2->data);
		v1->Srclist = addVertex(v1->Srclist, add2);
		v2->Dstlist = addVertex(v2->Dstlist, add1);*/
	}
	Graph g = malloc(sizeof(struct graph));
	g->v = v;
	g->num = count;
	return g;
}

/*Queue insert(Queue q, Vertex v){
	Vertex dup = malloc(sizeof(struct vertex));
	dup->vindex = v->vindex;
	dup->data = v->data;
	dup->next = v->next;
	return addVertex(q, dup);
}
Vertex delet(Queue q){
	if(q == NULL || q->head == NULL){return NULL;}
	else if(q->head != NULL && q->head == q->tail){
		Vertex v = q->head;
		q->head = q->tail = NULL;
		v->next = NULL;
		return v;
	}
	else if(q->head != NULL && q->head != q->tail){
		Vertex v = q->head;
		q->head = q->head->next;
		v->next = NULL;
		return v;
	}
}
Bool isEmpty(Queue q){
	if(q == NULL || q->head == NULL){return true;}
	else{return false;}
}

Label** BFS(Graph g, Vertex v){
	Enumeration e;
	Label** array = malloc(g->num * sizeof(Label*));
	for(int i = 0; i < g->num; i++){
		array[i] = malloc(g->num * sizeof(Label));
	}
	for(int i = 0; i < g->num; i++){
		for(int j = 0; j < g->num; j++){
			array[i][j] = unexplored;
		}
	}
	Bool visited[g->num];
	for(int i = 0; i < g->num; i++){visited[i] = false;}		
	Queue q = malloc(sizeof(struct vertexlist));
	q->head = NULL;
	q->tail = NULL;
	q = insert(q, v);
	Vertex u,w;
	while(!isEmpty(q)){
		u = delet(q);
		e = getAdjSrc(g, u);
		w = e->head;
		while(w != NULL){
			if(array[u->vindex][w->vindex] == unexplored){
				if(!visited[w->vindex]){
					printf("%d\t%d\n", w->vindex, w->data);
					//this is my visit()
					visited[w->vindex] = true;
					array[u->vindex][w->vindex] = treee;
					q = insert(q, w);
				}
				else if(visited[w->vindex]){
					array[u->vindex][w->vindex] = cross;
				}
			}
			w = w->next;
		}
	}
	return array;
}*/


Queue topsort(Graph g){
	Queue q = malloc(sizeof(struct vertexlist));
	int incounter[g->num];
	q->head = NULL;
	q->tail = NULL;
	Stack s = newStack(g->num);
	Vertex curr = g->v->head;
	Vertex add;
	Adj crawl;
	Enumeration adj;
	while(curr != NULL){
		incounter[curr->vindex] = indegree(g, curr);
		if(incounter[curr->vindex] == 0){s = push(s, curr);}
		curr = curr->next;
	}
	while(s->top != -1){
		curr = pop(s);
		//printf("%d\n", curr->data);
		add = newVertex(curr->vindex, curr->data);
		q = addVertex(q, add);
		adj = getAdjSrc(g, curr);
		crawl = adj->head;
		//printf("\t%d\n", crawl->data);
		while(crawl != NULL){
			incounter[crawl->v->vindex] = incounter[crawl->v->vindex] - 1;
			//printf("\t%d\n", incounter[crawl->vindex]);
			if(incounter[crawl->v->vindex] == 0){s = push(s, crawl->v);}
			crawl = crawl->next;
		}
	}
	if(s->top == -1){return q;}
	else{return NULL;}
}
	
