#include "tree.h"
int index=0;
int count=0;
t newNode(int val)	
{    
    t root =(t)malloc(sizeof(struct treeNode));
    root->value=val;
    root->left=NULL;
    root->right=NULL;
    root->bal=0;
    return root;
}
void inorder(t bt,int k)
{
	if(bt==NULL)
	return;
	inorder(bt->left,k);
	if(k==count)
	{printf("\n%d\n",bt->value);count++;return;}
	count++;
	inorder(bt->right,k);
}
int search(t root,int k1,int k2)
{
	if(root==NULL)
		return	0;
	if(root->value>k2)
	search(root->left,k1,k2);
	else if(root->value<k1)
	search(root->right,k1,k2);
	else
	{
		search(root->left,k1,root->value);
		global[index++]=root->value;
		search(root->right,root->value,k2);
	}
	return index;
}
t parentof(t root,t child)
{
	while(root->left!=child && root->right!=child)
	{
		if(child->value>root->value)
			root=root->right;
		else
			root=root->left;
	}
	return root;
}
int height(t root)
{
	if(root==NULL || (root->left==NULL && root->right==NULL))	
		return 0;
	else
	return 1+max(height(root->left),height(root->right));
}
t add(t root,int val)
{
    if(root==NULL)
    	root=newNode(val);
    else
    {
    if (root->value<val)
    	root->right=add(root->right,val);
    else
    	root->left=add(root->left,val);
    }
    return root;
}
t rotate(t bt,t x ,t y,t z)
{
	t t0,t1,t2,t3;
	t b;
	if(z->left==y &&y->left==x)
	{
		t2=y->right;
		y->left=x;
		y->right=z;
		z->left=t2;
		b=y;
	}
	else if(z->left==y && y->right==x)
	{
		t0=x->left;
		t1=x->right;
		x->left=y;
		x->right=z;
		y->right=t0;
		z->left=t1;
		b=x;
	}
	else if(z->right==y && y->left==x)
	{
		t0=x->left;
		t1=x->right;
		x->left=z;
		x->right=y;
		y->left=t1;
		z->right=t0;
		b=x;
	}
	else if(z->right==y &&y->right==x)
	{
		t2=y->left;
		y->left=z;
		y->right=x;
		z->right=t2;
		b=y;
	}
	return b;
}
t find(t root,int val)
{
    if(root==NULL)
    	return NULL;
    else if(root->value==val)
    	return root;
    else if(root->value>val)
    	find(root->left,val);
    else
    	find(root->right,val);
}
t delete(t root,int val)
{
    t temp1;
    if(root==NULL)return root;
    else
    {
        if(root->value>val)
        root->left=delete(root->left,val);
        else if(root->value<val)
        root->right=delete(root->right,val);
        else
        {
            if(root->right==NULL)
            {
                temp1=root->left;
                free(root);
                return temp1;
            }
            else if (root->left==NULL)
            {
                temp1=root->right;
                free(root);
                return temp1;
            }
            temp1=root->right;
            while(temp1->left!=NULL && temp1->right!=NULL)
            {prev=temp1;temp1=temp1->left;}
            root->value=temp1->value;
            root->right=delete(root->right,temp1->value);
        }
    }
    return root;
}
void print(t root)
{
    if(root==NULL)
    return;
    print(root->left);
    printf("%d ",root->value);
    print(root->right);
}

