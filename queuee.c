#include<stdio.h>
#define MaxLength 100
typedef struct{
    char name[30];
    char phone[20];
}address;
typedef address ElementType;
typedef struct {
ElementType Element[MaxLength];
int Front, Rear;
} Queue;
void MakeNull_Queue(Queue *Q){
Q->Front=-1;
Q->Rear=-1;
}
int Empty_Queue(Queue Q){
return Q.Front==-1;
}
int Full_Queue(Queue Q){
return (Q.Rear-Q.Front+1)==MaxLength;
}
void EnQueue(ElementType X,Queue *Q){
if (!Full_Queue(*Q)){
if (Empty_Queue(*Q)) Q->Front=0;
Q->Rear=Q->Rear+1;
Q->Element[Q->Rear]=X;
}
else printf("Queue is full!");
}
void DeQueue(Queue *Q){
if (!Empty_Queue(*Q)){
Q->Front=Q->Front+1;
if (Q->Front > Q->Rear)
MakeNull_Queue(Q);
}
else printf("Queue is empty!");
}
int main()
{
    int n,i;
    ElementType Ele;
    Queue Q;
    MakeNull_Queue(&Q);
    printf("So phan tu muon input:");scanf("%d%*c",&n);
    for(i=0;i<n;i++)
    {
       printf("Nhap ten:");gets(Ele.name);
       printf("Nhap sdt:");gets(Ele.phone);
       EnQueue(Ele,&Q);
    }
    //DeQueue(&Q);
    while(Q.Front <= Q.Rear)
    {
        printf("%Ten:%s\n",Q.Element[Q.Front].name);
        printf("SDT:%s\n",Q.Element[Q.Front].phone);
        Q.Front++;
    }
    return 0;
}
    