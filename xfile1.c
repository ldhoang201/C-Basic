#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    FILE *ptr;
    FILE *ptr1;
    char s[100];
    int i=1;
    ptr=fopen("lab1.txt","r");
    ptr1=fopen("lab1w.txt","w");
    if(ptr==NULL)
    {
        printf("K the mo file lab1.txt!\n");
    }
    else
    { 
    while(!feof(ptr))
    {
        fgets(s,20,ptr);
        fprintf(ptr1,"%d ",i);
        i++;
        fputs(s,ptr1);
    }
    }
    fclose(ptr);
    fclose(ptr1);
    return 0;
}