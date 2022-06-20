#include<stdio.h>
#include<stdlib.h>
int main()
{
    int* p;
    int i;
    p=(int*)malloc(5*sizeof(int));
    for(i=0;i<5;i++)
    {
        printf("Nhap phan tu thu %d:",i+1);
        scanf("%d",&p[i]);
    }
    for(i=4;i>=0;i--)
    {
        printf("%d",p[i]);
        printf("\t");
    }
    free(p);
    return 0;
}