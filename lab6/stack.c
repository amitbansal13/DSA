#include "stack.h"
stack newStack()
{
    stack s=(stack)malloc(sizeof(struct stack));
    s->top=NULL;
    return s;
}
stack push(stack s,int lo,int hi)
{
    node temp=newNode(lo,hi);
    if(s->top==NULL)
    {
        s->top=temp;
        return s;
    }
    temp->next=s->top;
    s->top=temp;
    return s;
}
node newNode(int lo,int hi)
{
    node n=malloc(sizeof(struct ele));
    n->lo=lo;
    n->hi=hi;
    return n;
}
int isEmpty(stack s)
{
    if(s->top==NULL)
        return 1;
    return 0;
}
stack pop(stack s)
{
    if(s->top==NULL)
        return s;
    node temp=s->top;
    s->top=s->top->next;
    free(temp);
    return s;
}
node top(stack s)
{
    return s->top;
}
