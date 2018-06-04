#include "SeqList.h"

SeqList newList()
{
    SeqList a = (SeqList)malloc(sizeof(struct seqList));
    a->count=0;
    a->head=NULL;
    a->tail=NULL;
    return a; 
}
SeqList insertInOrder(SeqList sl, Element e)
{
    Element temp=sl->head;
    Element prev=NULL;
    if(sl->head==NULL)
    {
        sl->count=1;
        sl->head=e;
        sl->tail=e;
    }
    else
    {
        sl->count++;/*
        if(sl->head->key>e->key)
        {
            e->next=sl->head;
            sl->head=e;
            
        }
        else
        {
            if(sl->count==2)
            {
                temp->next=e;
                return sl;
            }
            else{
            while(temp->next!=NULL && temp->next->key<e->key)
                temp=temp->next;    
            e->next=temp->next;
            temp->next=e;
            }
        }*/
        while(temp!=NULL && temp->key<e->key)
        {
        	prev=temp;
        	temp=temp->next;
        }
        if(prev)
        {
        	prev->next=e;
        	e->next=temp;
        }
        else
        {
        	e->next=temp;
        	sl->head=e;
        }
    }
            
    return sl;
}
SeqList insertAtFront(SeqList sl, Element e)
{
    if(sl->head==NULL)
    {
        sl->count=1;
        sl->head=e;
        sl->tail=e;
    }
    else
    {
        sl->count++;
        e->next=sl->head;
        sl->head=e;
    }
    
    return sl;
}
SeqList insertAtEnd(SeqList sl, Element e)
{
    Element temp=sl->head;
    if(sl->head==NULL)
    {
        sl->count=1;
        sl->head=e;
        sl->tail=e;
    }
    else
    {
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=e;
        sl->tail=e;
        e->next=NULL;
        sl->count++;

    }
    return sl;
}
SeqList delete(SeqList sl, Element e)
{
    Element temp=sl->head;
    Element prev=NULL;
    if(sl->head==NULL)
        return sl;
    else
    {
        if(sl->head==e)
        {
            sl->head=sl->head->next;
            free(temp);
        }
        else
        {
            while(temp!=NULL && temp!=e)
            {
                prev=temp;
                temp=temp->next;
                            
            }
            if(temp==NULL)
                return sl;
            else
            {
                if(temp->next==NULL)
                sl->tail=prev;
                prev->next=temp->next;
                free(temp);
            }    
        }    
        
    }
    return sl;
    
}
SeqList deleteAtFront(SeqList sl)
{
    Element temp=sl->head;
    if(temp==NULL)
    return sl;
    else
    {
        if(sl->count==1)
        {
            free(sl->head);
            sl->head=NULL;
            sl->tail=NULL;
            sl->count=0;
        }
        else
        {
            sl->head=temp->next;
            free(temp);
            sl->count--;
        }
    
    }
    return sl;    

}
Element find(SeqList sl, int key)
{
    if(sl->head==NULL)
        return NULL;
    else
    {
        Element temp=sl->head;
        while(temp!=NULL && temp->key!=key)
        temp=temp->next;
        return temp;
    }
}
Element newElement(int data)
{
    Element a=(Element)malloc(sizeof(struct element));
    a->key=data;
    a->next=NULL;
    return a;
}

