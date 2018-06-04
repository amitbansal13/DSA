#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
struct credit
{
	long long int num;
	char code[6];
	char exp[8];
	char fname[6];
	char lname[6];
};
typedef struct credit credit;
typedef long long int ll;
#endif
