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
node *CreateNode(int value){
    node *temp; 
    temp = (node*)malloc(sizeof(struct LinkedList)); 
    temp->next = NULL;
    temp->data = value; 
    return temp;
}
node *AddHead(node* head, int value){
    node *temp = CreateNode(value); 
    if(head == NULL){
        head = temp; 
    }else{
        temp->next = head; 
        head = temp; 
    }
    return head;
}
node *AddTail(node *head, int value){
    node *temp,*p;
    temp = CreateNode(value);
    if(head == NULL){
        head = temp;
    }
    else{
        node *ps=head;
        while(ps->next != NULL){
            ps = ps->next;
        }
        ps->next = temp;
    }
    return head;
}
node *Input(){
    node *head=InitHead();
    int n, value;
    do{
        printf("\nInput the number of data u wanna input = ");
        scanf("%d", &n);
    }while(n <= 0);
 
    for(int i = 0; i < n; i++){
        printf("\nInput data: ");
        scanf("%d", &value);
        head = AddTail(head, value);
    }
    return head;
}
void Traverser(node *head){
    printf("\n");
    for(node *p = head; p != NULL; p = p->next){
        printf("%5d", p->data);
    }
    printf("\n");
}
int search(node *head,int x)
{
    int pos=1;
    for(node *p=head;p!=NULL;p=p->next)
    {
        if(p->data==x)
        return pos;
        pos++;
    }
    return -1;
}
int main()
{
  int pos;
  node *head = InitHead();
  head=Input();
  printf("\n");
  Traverser(head);
  return 0;
}