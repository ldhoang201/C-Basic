#include<stdio.h>
#define MAX 100
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void bubble_sort(int a[],int size)
{
    int i,j;
    int temp;
    for(i=0;i<6;i++)
    for(j=i+1;j<6;j++)
    {
        if(a[i]>a[j])
            swap(&a[i],&a[j]);
    }
}
int main()
{
    int a[MAX]={15,12,6,9,40,25};
    bubble_sort(a,MAX);
    for(int i=0;i<6;i++)
    {
        printf("%d\t",a[i]);
    }
    return 0;
}