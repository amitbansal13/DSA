#include "ex3.h"
#include <time.h>
int main()
{
	srand(time(NULL));
	Tree t=createTree(rand()%11,0);
	printf("NORMAL\n\n\n");
	printTree(t);
	printf("\n\n\nDFT\n\n\n");
	dft(t);
	bft(t);
	return 0;
}
