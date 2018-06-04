#include "SeqList.h"

SeqList merge(SeqList s1,SeqList s2)
{
    SeqList sl=newList();
    Element temp1=s1->head;
    if(temp1==NULL)
    return s2;
    if(s2->head==NULL)
    return s1;    
    while(temp1!=NULL)
    {
    insertInOrder(sl,temp1);
    temp1=temp1->next;
    }
    temp1=s2->head;    
    while(temp1!=NULL)
    {
    insertInOrder(sl,temp1);
    temp1=temp1->next;
    }
    return sl;
}
SeqList insertionSort(SeqList s1)
{
    SeqList sl=newList();
    Element temp1=s1->head;
    while(temp1!=NULL)
    {
    insertInOrder(sl,temp1);
    temp1=temp1->next;
    }
    return sl;
}
