#include<stdio.h>
int gtcal(int a)
{
    int i,b=1;
    for(i=1;i<=a;i++)
    b=b*i;
    return b;
}
int main()
{
    int a;
    printf("Nhap so can tinh giai thua:");scanf("%d",&a);
    printf("Kq:%d",gtcal(a));
    return 0;
}