#include <stdio.h>
#define MAX 100
typedef struct 
{
    int arr[MAX];
    int top;
} StackType;
void Initialize(StackType *stack) 
{ 
    (*stack).top=0;
}
int empty(StackType stack)
{
    return stack.top==1;
}
int full(StackType stack)
{
    return stack.top==MAX;
}
void pushstack(StackType *stack,int x)
{
    if(full(*stack))
    {
        printf("stack tran ne!\n");
    }
    else 
    {
    (*stack).arr[(*stack).top++]=x;
    }
}
int pop(StackType *stack)
{
    {
        return (*stack).arr[--(*stack).top];
    }
}
int main()
{
    StackType stack;
    int x;
    Initialize(&stack);
    for(int i=0;i<3;i++)
    {
        printf("Nhap value:");scanf("%d",&x);
        printf("\n");
        pushstack(&stack,x);
    }
    stack.top--;
    while(stack.top >= 0)
    {
        printf("%d\n",stack.arr[stack.top]);
        stack.top--;
    }
    return 0;
}