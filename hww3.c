#include<stdio.h>
#include<string.h>
#define max 100
typedef struct 
{
 char name[20];
 char tell[20];
 char email[30];   
} phonebook;
int main()
{
    FILE* ptr,*ptr1;
    ptr=fopen("lab2.txt","w+");
    ptr1=fopen("lab2a.txt","w");
    phonebook str[max];
    phonebook str1[max];
    int i;
    for(i=0;i<1;i++)
    {
        printf("Nhap thong tin nguoi thu %d\n",i+1);
        printf("Nhap ten:");gets(str[i].name);
        printf("Nhap SDT:");gets(str[i].tell);
        printf("Nhap email:");gets(str[i].email);
    }
    for(i=0;i<1;i++)
    {
        fprintf(ptr,"Thong tin nguoi thu %d\n",i+1);
        fprintf(ptr,"%s","Ten:");
        fwrite(str->name,sizeof(char),strlen(str[i].name),ptr); fprintf(ptr,"%s","\n");
        fprintf(ptr,"%s","SDT:");
        fwrite(str->tell,sizeof(char),strlen(str[i].tell),ptr); fprintf(ptr,"%s","\n");
        fprintf(ptr,"%s","Email:");
        fwrite(str->email,sizeof(char),strlen(str[i].email),ptr); fprintf(ptr,"%s","\n");
    }
    fclose(ptr);
    fclose(ptr1);
    return 0;
}
