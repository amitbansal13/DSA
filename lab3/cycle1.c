#include "cycle.h"

int findCycle(List l)
{
  node hare=l->head;
  node tort=l->head;
  while(hare!=NULL && tort!=NULL && hare->next!=NULL)
  {
    hare=hare->next->next;
    tort=tort->next;
    if(hare==tort)
      return 1;
  }
  return 0;
}
