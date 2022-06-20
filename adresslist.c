#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct 
{
    char name[30];
    char phone[15];
} address;
struct LinkedList{
    address data;
    struct LinkedList *next;
 };
typedef struct LinkedList node;
node *InitHead(){
    node *head;
    head = NULL;
    return head;
} 
node *CreateNode(address value){
    node *temp; 
    temp = (node*)malloc(sizeof(struct LinkedList)); 
    temp->next = NULL;
    temp->data = value; 
    return temp;
}
node *AddHead(node* head, address value){
    node *temp = CreateNode(value); 
    if(head == NULL){
        head = temp; 
    }else{
        temp->next = head; 
        head = temp; 
    }
    return head;
}
node *AddTail(node *head, address value){
    node *temp,*p;
    temp = CreateNode(value);
    if(head == NULL){
        head = temp;
    }
    else{
        p=head;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = temp;
    }
    return head;
}
node *Input(int n){
    node *head=InitHead();
    int value;
    address temper;
    for(int i = 0; i < n; ++i){
        printf("\nInput name: ");
        gets(temper.name);
        printf("\nInput phone number: ");
        gets(temper.phone);
        head = AddTail(head,temper);
    }
    return head;
}
void Traverser(node *head){
    printf("\n");
    for(node *p = head; p != NULL; p = p->next){
        printf("%s\n",p->data.name);
        printf("%s\n",p->data.phone);
        printf("\n");
    }
    printf("\n");
}
node* search(node *p,char namee[],FILE *ptr)
{
    for(p;p!=NULL;p=p->next)
    {
    if(strcmp(p->data.name,namee)==0)
    {
        fputs((p->data.name),ptr);
        fprintf(ptr,"\n");
        fputs((p->data.phone),ptr);
        return p;
    }
    }
}
int main()
{
    FILE *ptr;
    ptr=fopen("f1.txt","w");
    node *p;
    node *temp;
    int n;
    char namee[30];
    address data;
    printf("The num you wanna push to list:");scanf("%d%*c",&n);
    p=Input(n);
    Traverser(p);
    //printf("The name you wanna search:");gets(namee);
    //p=search(p,namee,ptr);
    //Traverser(p);
    return 0;
}