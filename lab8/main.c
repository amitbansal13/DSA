#include "tree.h"
#include<stdlib.h>
int main()
{
    srand(time(NULL));
    int i=0;
    t tree=NULL;
    for(i=0;i<60;i++)
        tree=add(tree,rand()%100);
    print(tree);
    inorder(tree,4);
    /*t temp=find(tree,61);
    if(temp)
    printf("%d\n",temp->value);
    else 
    printf("NULL\n");
    
    Working
    print(tree);
    printf("\n");
    int index=search(tree,30,40);
   	for(i=0;i<index;i++)
   	printf("\n%d",global[i]);
   	Working
   	*/
   	
   	
}
