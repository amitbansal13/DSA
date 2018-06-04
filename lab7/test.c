#include "hash.h"
int main()
{
    file *f=read("aliceinwonderland.txt");
    Table t=create();
    insertAll(t,f->r,f->size);
    float size=profiling(t,f->r,f->size);
    //link l=lookup(t,"splashing",f->r);
    cleanup(t,f->r,f->size);
    return 0;
}
