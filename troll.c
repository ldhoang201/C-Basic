#include<stdio.h>
void prii(char c,int n)
{
    printf("\t");
    for(int i=0;i<n;i++)
    {
        printf(" %c",c);
    }
    printf("\n");
    if(n < 7)
    prii(c,n+1);
    else return;
}
int main()
{
    char s;
    s='$';
    int n=1;
    prii(s,n);
    return 0;
}
