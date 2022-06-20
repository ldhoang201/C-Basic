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
NODE * addhead(NODE *p,int value)
{
    NODE *temp=listcreate(value);
    if(p==NULL) p=temp;
    else
    {
        temp->next=p;
        p=temp;
    }
    return p;
}
NODE *addtail(NODE *p,int value)
{
    NODE *temp;
    NODE *ps;
    temp=listcreate(value);
    if(p==NULL) 
    {
        p=temp;
        return p;
    }
    else
    {
        ps=p;
        while(ps->next!=NULL)
        {
            ps=ps->next;
        }
        ps->next=temp;
        return p;
    }
}
NODE *deltail(NODE *p)
{
    while(p->next->next!=NULL)
    {
        p=p->next;
    }
    p->next=p->next->next;
    return p;
}
NODE *addat(NODE *p,int pos,int value)
{
    if(pos==0||p==NULL)
    p=addhead(p,value);
    else
    {
        NODE *ps=p;
        int k=1;
        while(ps->next!=NULL&&k!=pos)
        {
            ps=ps->next;
            k++;
        }
        if(pos!=k)
        printf("Error pos!\n");
        else
        {
            NODE *temp=listcreate(value);
            temp->next=ps->next;
            ps->next=temp;
        }
    }  
    return p;
}
NODE *delat(NODE *p,int pos)
{
    if(pos==0||p==NULL)
    {
       printf("Nothing to delete ne !\n");
    }
    else
    {
        NODE *ps=p;
        int k=1;
        while(ps->next->next!=NULL&&k!=pos)
        {
            ps=ps->next;
            k++;
        }
        if(k!=pos) printf("Error pos!\n");
        else
        {
            ps->next=ps->next->next;
        }
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
void oput(NODE *p)
{
    for(p;p!=NULL;p=p->next)
    {
        printf("%d",p->data);
        printf("\t");
    }
}
void sapxep(NODE *head)
{
   for(NODE *p=head;p!=NULL;p=p->next)
   {
       for(NODE *ps=p->next;ps!=NULL;ps=ps->next)
       {
           if(p->data<ps->data)
           {
               int temp=p->data;
               p->data=ps->data;
               ps->data=temp;
           }
       }
   }
}
int main()
{
    NODE *p,*temp;
    int n;
    int a=8;
    printf("Da num you wanna put in:");scanf("%d",&n);
    p=iput(n);
    temp=p;
    printf("\n");
    oput(p);
    printf("\n");
    sapxep(p);
    oput(p);
    return 0;
}