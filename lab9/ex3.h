#include "ex2.h"
typedef struct currentSet *curr;
struct currentSet
{
	int count;
	Element	head;
	Element tail;
};
Iterator identifyMoreNodes(curr c);
void addMoreNodes(curr c,Iterator i);
Element selectNextNode(curr c);
Element newElement(Tree t);
void dft(Tree g);
void bft(Tree g);
