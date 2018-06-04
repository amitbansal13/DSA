#include "hash.h"
int hashFunction(char s[],long long int  baseNumber,int tableSize)
{
    long long sum=0;
    int i=0;
    while(s[i]!='\0')
        {sum+=(int)s[i];i++;}
    sum=((sum%baseNumber)*(1000003%baseNumber))%baseNumber;
    return sum%tableSize;
}
int colCount(char *s[],int size,long long baseNumber,int tableSize)
{
    int i=0;
    int arr[tableSize];
    for(i=0;i<tableSize;i++)
        arr[i]=0;
    for(i=0;i<size;i++)
    {
        arr[hashFunction(s[i],baseNumber,tableSize)]++;
    }
    int c=0;
    for(int i=0;i<tableSize;i++)
        if(arr[i]>1)
            c+=arr[i]-1;
    return c;
}
file *read(char *name)
{
	file *f1=malloc(sizeof(file));
	int count=0;
    FILE *f=fopen(name,"r");
    char **str=(char**)malloc(sizeof(char*)*10);
    for(int i=0;i<10;i++)
    {
        str[i]=(char*)malloc(sizeof(char)*70);
    }
    char s[70];
    int def=10;
    count=0;
    while(fscanf(f,"%s",s)!=-1)
    {
        int i=0;
        int flag=1;
        while(s[i]!='\0')
        {
            if(isalpha(s[i])==0)
            {
                flag=0;
                break;
            }
        i++;
        }
        if(flag)
        {
            if(count==def-1)
            {
                def+=10;
                str=(char**)realloc(str,sizeof(char*)*def);
                for(int  i=count;i<def;i++)
                {
                    str[i]=(char*)malloc(sizeof(char)*70);
                }
            }
            strcpy(str[count++],s);
        }
        
    }
    printf("The number of valid words is %d\n",count);
    f1->size=count;
    f1->r=str;
    return f1;
    
}
void profile(char *s[],int size)
{
        long long prime[3][6]={{7681,8089,6389,5001539,5002847,5003227},{76387,76403,76421,50003297,50003299,50003309},{759637,759641,759653,500018131,500018179,500018221}};
        int tableSize[3]={5000,50000,500000};
        int minI=0,minT=0;
        int i=0,j=0;
        int col;
        int min;
        min=colCount(s,size,prime[0][0],5000);
        for(i=0;i<3;i++)
        {
            for(j=0;j<6;j++)
            {
                col=colCount(s,size,prime[i][j],tableSize[i]);
                if(col<min)
                {
                    minI=j;
                    minT=i;
                    min=col;
                }                                          
                printf("The collisions count for %lld BaseNumber & %d tableSize is %d\n",prime[i][j],tableSize[i],col);
                
            }
        
        }
        printf("\nThe minimum collisions are there for %lld baseNumber & %d tableSize\n",prime[minT][minI],tableSize[minT]);              
}
/*Excercise 2*/
link lookup(Table t,char arr[],char *a[])
{
	int count=0;
	int key=hf(arr);
	link list=(t->chains)[key];
	if(list==NULL)
		return NULL;
	while(list!=NULL && strcmp(arr,a[list->index])!=0)
	{
		count++;
		list=list->next;
	}
	t->queryingCost+=count;
	return list;
}
int lookupAll(Table t,char *arr[],int size,float m)
{
	int s=(int)(size*m);
	int i=0;
	t->queryingCost=0;
	for(i=0;i<s;i++)
		lookup(t,arr[i%size],arr);
	return t->queryingCost;
}
int hf(char s[])
{
    long long sum=0;
    int i=0;
    while(s[i])
        {sum+=s[i];i++;}
    sum=((sum%7681)*(1000003%7681))%7681;
    return sum%5000;
}
Table create()
{
    Table t=(Table)malloc(sizeof(struct hash));
    t->elementCount=0;
    t->insertionCost=0;
    t->queryingCost=0;
    t->tableSize=5000;
    t->chains=(link*)malloc(sizeof(link)*5000);
    int i=0;
    for(i=0;i<5000;i++)
        t->chains[i]=(link)malloc(sizeof(struct record));  
    return t;
}
Table insert(Table t,char *a[],int j)
{
	int cost=0;
    int k=hf(a[j]);
    link x=((t->chains)[k]);
    t->elementCount++;
    if(x->count==0)
    {
        x->count=1;
        x->index=j;
        x->next=NULL;
        cost++;
    }
    else
    {
    	link temp=x;
    	link prev=NULL;
    	while(temp!=NULL &&strcmp(a[j],a[temp->index])!=0)
    	{prev=temp;temp=temp->next;cost++;}
    	if(temp==NULL)
    		prev->next=newNode(j);
    	else
    		temp->count++;
    }
    t->insertionCost+=cost;
    return t;
}
int insertAll(Table t,char *s[],int size)
{
    int i;
    for(i=0;i<size;i++)
        t=insert(t,s,i);
    return t->insertionCost;
}
link newNode(int index)
{
	link l=(link)malloc(sizeof(struct record));
	l->index=index;
	l->count=1;
	l->next=NULL;
	return l;
}



//Excercise 3


float profiling(Table t,char *book[],int size)
{
	float f=0.1;
	int icost=t->insertionCost;
	int qcost=lookupAll(t,book,size,f);;
	printf("The qcost is %d icost is %d The float value is %f\n",qcost,icost,f);
	while(f<2.1)
	{
		f+=0.1;
		qcost=lookupAll(t,book,size,f);
		printf("The qcost is %d icost is %d The float value is %f\n",qcost,icost,f);
		if(qcost>icost)break;
	}
	return f;
}

void cleanup(Table t,char **arr,int size)
{
		FILE *fp=fopen("stopwords.txt","r");
		char s[70];
		while(fscanf(fp,"%s\n",s)!=-1)
		{
			int h=hf(s);
			link list=(t->chains)[h];
			link prev=NULL;
			while(list!=NULL && strcmp(s,arr[list->index])!=0)
			{prev=list;list=list->next;}
			if(list==NULL)continue;
			if(list->count>1)
			list->count--;
			else
			{
				if(prev==NULL)
				{
					(t->chains)[h]=list->next;
					free(list);
				}
				else
				{
					prev->next=list->next;
					free(list);
				}
			}
		}
		printf("\nAfter Cleanup\n");
		profiling(t,arr,size);
}









