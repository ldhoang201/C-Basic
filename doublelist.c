#include<stdio.h>
#include<stdlib.h>
 
struct Node  {
    int data;
    struct Node* next;
    struct Node* prev;
};
 
struct Node *head, *tail; // Khởi tạo Node head global của dslk đôi.
 
//Creates a new Node and returns pointer to it.
struct Node* GetNewNode(int x) {
    struct Node* newNode
        = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
 
//Inserts a Node at head of doubly linked list
void InsertAtHead(int x) {
    struct Node* newNode = GetNewNode(x);
    if(head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}
 
//Inserts a Node at tail of Doubly linked list
void InsertAtTail(int x) {
    struct Node* newNode = GetNewNode(x);
    if(head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}
 
 
void DeleteAtHead() {
    if(head == NULL) {
        return;
    }
    head = head->next;
    head->prev = NULL;
}
 
//Inserts a Node at tail of Doubly linked list
void DeleteAtTail() {
    if(head == NULL) {
        return;
    }
    tail = tail->prev;
    tail->next = NULL;
}
 
//Prints all the elements in linked list in forward traversal order
void Print() {
    struct Node* temp = head;
    printf("\nForward: ");
    while(temp != NULL) {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
 
//Prints all elements in linked list in reverse traversal order.
void ReversePrint() {
    struct Node* temp = tail;
    if(temp == NULL) return; // empty list, exit
    // Traversing backward using prev pointer
    printf("\nReverse: ");
    while(temp != NULL) {
        printf("%d ",temp->data);
        temp = temp->prev;
    }
    printf("\n");
}
 
int main() {
 
    /*Driver code to test the implementation*/
    head = NULL;
    struct Node* temp;
    int x;
    for(int i=0;i<5;i++)
    {
        printf("Input valuee:");scanf("%d",&x);
        InsertAtTail(x);
    }
    Print();
    return 0;
}