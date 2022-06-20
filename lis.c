#include<stdio.h>
#include<stdlib.h>
typedef struct list
{
    int data;
    struct list *next;
} NODE;
NODE *listcreate(int value)
{
    NODE *p;
    p=(NODE*)malloc(sizeof(NODE));
    p->next=NULL;
    p->data=value;
    return p;
}
NODE *InitHead(){
    NODE *head;
    head = NULL;
    return head;
}
NODE *addhead(NODE *p,int value)
{
    NODE *temp;
    temp=listcreate(value);
    if(p==NULL) {
        p=temp;
    }
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
NODE *dehead(NODE *p)
{
    if(p==NULL) printf("D co gi de xoa!\n");
    else
    {
        p=p->next;
    }
    return p;
}
NODE *detail(NODE *p)
{
    if(p==NULL||p->next==NULL)
    {
        return dehead(p);
    }
    else
    {
       NODE *ps=p;
       while(ps->next->next!=NULL)
       {
           ps=ps->next;
       }
       ps->next=ps->next->next;
    }
    return p;
}
int search(NODE *p,int value)
{
    int pos=1;
    for(NODE *ps=p;ps!=NULL;ps=ps->next)
    {
        if(ps->data==value)
        return pos;
        pos++;
    }
    return -1;
}
NODE *addat(NODE *p,int value,int pos)
{
    if(pos == 0 || p == NULL){
        p = addhead(p,value);
    }else{
        int k=1;
        NODE *ps=p;
        while(ps!=NULL&&k!=pos) 
        {
            ps=ps->next;
            k++;
        }
    if(k!=pos) 
    {
        printf("K tim thay pos => auto addtail ne!\n");
        p=addtail(p,value);
    }
    else
    {
        NODE *temp=listcreate(value);
        temp->next=p->next;
        p->next=temp;
    }
    }
    return p;
}
NODE *delat(NODE *p,int pos)
{
    if(p==NULL) printf("Nothing to delete!\n");
    else
    { 
        NODE *ps=p;
        int k=1;
        while(ps->next->next!=NULL&&k!=pos)
        {
           ps=ps->next;
           k++;
        }
        if(k==pos)
        {
           ps->next=ps->next->next;
        }
    }
    return p;
}
NODE *Iput(int n)
{
   NODE *p=InitHead();
   int i,value;
   for(i=0;i<n;i++)
   {
       printf("Nhap value:");scanf("%d",&value);
       printf("\n");
       p=addtail(p,value);
   }
   return p;
}
void Oput(NODE *p)
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
    int n,value;
    printf("Nhap n:");scanf("%d",&n);
    p=Iput(n);
    Oput(p);
    printf("\n");
    p=delat(p,3);
    Oput(p);
    return 0;
}