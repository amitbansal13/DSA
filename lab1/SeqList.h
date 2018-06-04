#include <stdlib.h>
typedef struct element* Element;
typedef struct seqList* SeqList;

struct seqList
{
    int count;
    Element head;
    Element tail;    
};
struct element 
{
    int key;
    Element next;

};
SeqList newList();
SeqList insertInOrder(SeqList sl, Element e); // add e to sl in order of key assuming sl is
SeqList insertAtFront(SeqList sl, Element e); // add e at the front of the list; return the modified
SeqList insertAtEnd(SeqList sl, Element e);// add e at the end of the list; return the modified list
SeqList delete(SeqList sl, Element e) ;// delete e from sl; return the modified list
SeqList deleteAtFront(SeqList sl);// delete the first element from sl; return the modified list
Element find(SeqList sl, int key); // find the element e with key k in sl; return e SeqList 
Element newElement(int data);



