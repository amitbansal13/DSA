#include <stdio.h>
#include <stdlib.h>
typedef struct tnode *Tree;
typedef struct iter *Iterator;
typedef struct element *Element;
typedef struct iter
{
	int size;
	int count;
	Element *arr;
}iter;
struct element
{
	Tree t;
};
int hasMoreElements(Iterator it);
Element getNextElement(Iterator it);
