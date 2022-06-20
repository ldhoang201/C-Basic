#include<stdio.h>
#include<string.h>
void replace(char s[],char a,char b)
{
    int i;
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]==a)
        s[i]=b;
    }
}
int main()
{
    char s[30];
    char a,b;
    printf("Nhap vao 1 xau ki tu:");gets(s);
    printf("Nhap a:");scanf("%c%*c",&a);
    printf("Nhap b:");scanf("%c",&b);
    replace(s,a,b);
    printf("after replcing:%s\n",s);
    return 0;
}