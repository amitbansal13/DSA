#ifndef STACK_H
#define STACK_H
#include <stdio.h>
#include<stdlib.h>
typedef struct ele *node;
struct ele
{
    int lo;
    int hi;
    node next;
};
struct stack
{
    node top;
};
typedef struct stack* stack;
stack newStack();
stack push(stack s,int lo,int hi);
node newNode(int lo,int hi);
node top(stack s);
stack pop(stack s);
int isEmpty(stack s);
#endif
