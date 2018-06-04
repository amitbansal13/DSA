#include "SeqList.h"
#include <stdio.h>
void print(SeqList sl)
{
    Element temp=sl->head;
    while(temp!=NULL)
    {
        printf("%d->",temp->key);
        temp=temp->next;    
    }    
    printf("NULL\n");
}
int main()
{
    
    Element a=newElement(6);
    Element b=newElement(7);
    Element c=newElement(8);
    Element d=newElement(9);
    Element e=newElement(4);
    SeqList s=newList();
    s=insertInOrder(s,a);
    print(s);    
    s=insertInOrder(s,b);
    print(s);    
    s=insertInOrder(s,e);
    print(s);
    s=insertInOrder(s,d);
    print(s);
    s=insertInOrder(s,c);
    print(s);/*
    printf("\nList2\n\n");
    SeqList s1=newList();
    s1=insertAtFront(s1,c);
    print(s1);    
    s1=insertAtEnd(s1,e);
    print(s1);    
    s1=insertAtEnd(s1,a);
    print(s1);
    */
    return 0;
}
