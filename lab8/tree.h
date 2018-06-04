#include <stdio.h>
#include<time.h>
#include<stdlib.h>
#define max(a,b) a>b?a:b
int global[100];
typedef struct treeNode *t;
struct treeNode
{
    int value;
    t left;
    t right;
    int bal:2;
};
t newNode(int val);
t add(t root,int val);
t find(t root,int val);
t delete(t root,int val);
t rotate(t bt,t x ,t y,t z);
void print(t root);
int height(t root);
void inorder(t bt,int k);
int search(t root,int k1,int k2);
