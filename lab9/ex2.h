#include "iter.h"
#define maxh 5
struct tnode
{
	int value;
	Iterator it;
};
Tree createTree(int n,int h);
int isEmpty(Tree t);
Element getRootVal(Tree t);
Iterator getChildren(Tree t);
void printTree(Tree t);
