#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Max 50
typedef struct {
    char name[30];
    char phone[20];
    char email[20];
} address;
typedef address Eltype;
typedef struct {
    Eltype storage[Max];
    int top;
} StackType;

void initialize(StackType *stack)
{
    (*stack).top=0;
}
int empty(StackType stack)
{
    return stack.top==0;
}
int full(StackType stack)
{
    return stack.top==Max;
}
void push(Eltype el,StackType *stack)
{
    if(full(*stack))
    printf("stack full ne!\n");
    else
    {
        (*stack).storage[(*stack).top++]=el;
        //printf("name:%s \n",el.name);
    }
}
Eltype pop(StackType *stack)
{
    if(empty(*stack))
    printf("stack rong ne!\n");
    else
    {
        return (*stack).storage[--(*stack).top];
    }
}
int main()
{
    Eltype str[Max];
    Eltype data,str1[Max];
    StackType stack;
    FILE *ptr,*ptr1;
    ptr=fopen("41.txt","r");
    ptr1=fopen("d41.txt","w");
    int count  =0;
    if(ptr==NULL)
    printf("file 41 rong ne!\n");
    else
    {
        initialize(&stack);
        while(!feof(ptr))
        {
            fgets((str[count].name),30,ptr);
            fgets((str[count].phone),30,ptr);
            fgets((str[count].email),30,ptr);
            push(str[count],&stack);
            count++;
        }
    }
    for(count=0;count<2;count++)
    {
        data = pop(&stack);
        fputs(data.name,ptr1);
        fputs(data.phone,ptr1);
        fputs(data.email,ptr1);
        printf("\n");
    }
    fclose(ptr);
    fclose(ptr1);
    return 0;
}