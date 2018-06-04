#include "cycle.h"

int findCycle(List l)
{

  node prev=NULL,curr=l->head,next;
  while(curr!=NULL)
  {
    next=curr->next;
    curr->next=prev;
    prev=curr;
    curr=next;
  }
  if(prev==l->head)
  return 1;
return 0;
}
