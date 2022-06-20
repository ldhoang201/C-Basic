#include<stdio.h>
#include<stdlib.h>
typedef struct list{
    int data;
    struct list *next;  
} NODE;
NODE * listcreate(int value)
{
    NODE *temp;
    temp=(NODE*)malloc(sizeof(NODE));
    temp->next=NULL;
    temp->data=value;
    return temp;
}
NODE *inhead()
{
    NODE *p;
    p=NULL;
    return p;
}
NODE *addtail(NODE *p,int value)
{
    NODE *temp;
    NODE *ps;
    temp=listcreate(value);
    if(p==NULL) p=temp;
    else
    {
        ps=p;
        while(ps->next!=NULL)
        {
            ps=ps->next;
        }
        ps->next=temp;
    }
    return p;
}
NODE * iput(int n)
{
   NODE *p=inhead();
   int i,x;
   for(i=0;i<n;i++)
   {
       printf("Input data ne:");scanf("%d",&x);
       printf("\n");
       p=addtail(p,x);
   }
   return p;
}
int findmax(NODE *ps)
{
    int max=0;
    for(ps;ps!=NULL;ps=ps->next)
    {
        if(ps->data>max)
        max=ps->data;
    }
    return max;
}
void oput(NODE *p)
{
    for(p;p!=NULL;p=p->next)
    {
    printf("%d",p->data);
    printf("\t");
    }
}
int main()
{
    NODE *p;
    int n;
    printf("Da num you wanna put in:");scanf("%d",&n);
    p=iput(n);
    oput(p);
    return 0;
}