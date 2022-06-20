#include<stdio.h>
#include<string.h>
int dem(char *s,char t)
{
 int dem=0;
 for(int i=0;i<=strlen(s);i++)
 {
 if(s[i]==t) dem=dem+1;  
 }
 return dem;
}
int main()
{
 char s[256];
 char t;
 printf("vui long nhap chuoi: ");
 gets(s);
 puts(s);
 printf("vui long 1 ky tu: ");
 scanf("%c",&t);
 printf("%c ",t);
 printf("so lan xuat hien cua ky tu %c la: %d",t,dem(s,t));
 return 0;
}