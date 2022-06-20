#include<stdio.h>
#include<stdlib.h>
 
struct LinkedList{
    int data;
    struct LinkedList *next;
 };
 
typedef struct LinkedList node;
node *InitHead(){
    node *head;
    head = NULL;
    return head;
} 
node *AddNode(node* p,int value){
    if(p==NULL)
    {
    node *temp; 
    temp = (node*)malloc(sizeof(struct LinkedList)); 
    temp->next = NULL;
    temp->data = value; 
    return temp;
    }
    else
    {
        p->next=AddNode(p->next,value);
        return p;
    }
}
void Traverser(node *head){
    printf("\n");
    for(node *p = head; p != NULL; p = p->next){
        printf("%5d", p->data);
    }
    printf("\n");
}
void bbsort(node *p)
{
    int temp;
    node *i,*j;
    for(i=p;i!=NULL;i=i->next)
    {
        for(j=p->next;j!=NULL;j=j->next)
        {
            if(i->data>j->data)
            {
                temp=i->data;
                i->data=j->data;
                j->data=temp;
            }
        }
    }
}
int main()
{
    node * head;
    head=InitHead();
    int value;
    for(int i=0;i<5;i++)
    {
        printf("Nhap data:");scanf("%d",&value);
        printf("\n");
        head=AddNode(head,value);
    }
    Traverser(head);
    bbsort(head);
    Traverser(head);
}
