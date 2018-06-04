#include "iterDynamic.h"
int hasMoreElements(Iterator it)
{
	if(it==NULL)return 0;
	if(it->count==it->size){it->count=0;return 0;}
	if(it->count<it->size)
		return 1;
	return 0;
}
Element getNextElement(Iterator it)
{
	it->count++;
	return (it->arr)[it->count-1];
}
