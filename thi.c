#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct thi
{
    char diadiem[50];
    char hour[20];
    char minute[20];
}covid19;
typedef struct list{
    covid19 data;
    struct list *next;  
} NODE;
NODE * listcreate(covid19 value)
{
    NODE *temp;
    temp=(NODE*)malloc(sizeof(NODE));
    temp->next=NULL;
    temp->data=value;
    return temp;
}
NODE *inhead()
{
    NODE *p;
    p=NULL;
    return p;
}
NODE *addtail(NODE *p,covid19 value)
{
    NODE *temp;
    NODE *ps;
    temp=listcreate(value);
    if(p==NULL) 
    {
        p=temp;
        return p;
    }
    else
    {
        ps=p;
        while(ps->next!=NULL)
        {
            ps=ps->next;
        }
        ps->next=temp;
        return p;
    }
}
void oput(NODE *p)
{
    for(p;p!=NULL;p=p->next)
    {
        printf("%-50s",p->data.diadiem);
        printf("%-10s",p->data.hour);
        printf("%-10s",p->data.minute);
        printf("\n");
    }
}
void checkarea(NODE*p,char checker[])
{
    for(p;p!=NULL;p=p->next)
    {
        if(strcmp(p->data.diadiem,checker)==0)
        {
            printf("%s:",p->data.hour);
            printf("%s",p->data.minute);
            printf(" ");
        }
    }
}
NODE *checktime(NODE *p,char our[],char min[])
{
    for(p;p->next;p=p=p->next)
    {
        if((our[0]==p->data.hour[0]&&our[1]==p->data.hour[1])&&(min[0]==p->data.minute[0]&&min[1]==p->data.minute[1]))
        return p;
    }
}
void freee(NODE *p)
{
    free(p);
    if(p!=NULL)
    freee(p->next);
}
int main()
{
    int choice;
    FILE *ptr;
    ptr=fopen("log.txt","r+");
    covid19 temp;
    char checker[100];
    NODE *p;
    NODE *ps;
    ps=inhead();
    char checkhour[20];
    char checkminte[20];
    int a,b;
    p=inhead();
    do{
    printf("\t\t\t\t_________________________________________________________________________\n");    
    printf("\t\t\t\t|------------------*CHUONG TRINH TRUY VIET COVID19*---------------------|\n");
    printf("\t\t\t\t|1)Nap file log lich su di chuyen                                       |\n");
    printf("\t\t\t\t|2)In ra lich su di chuyen                                              |\n");
    printf("\t\t\t\t|3)Tim kiem lich su theo dia diem                                       |\n");
    printf("\t\t\t\t|4)Tim kiem lich su theo thoi gian                                      |\n");
    printf("\t\t\t\t|5)Kiem tra truy vet moi nhat                                           |\n");
    printf("\t\t\t\t|6)Thoat                                                                |\n");
    printf("\t\t\t\t|_______________________________________________________________________|\n");
    printf("Ban chon(1,2,3,4,5,6):");scanf("%d%*c",&choice);
    switch (choice)
    {
    case 1:
    while (!feof(ptr))
    {
        fscanf(ptr,"%s",temp.diadiem);
        fscanf(ptr,"%s",temp.hour);
        fscanf(ptr,"%s",temp.minute);
        p=addtail(p,temp);
    }   
    break;
    case 2:
    printf("%-50s%-10s%-10s\n","Dia diem","Gio","Phut");
    oput(p);
    break;
    case 3:
    printf("Nhap vao dia diem:");gets(checker);
    checkarea(p,checker);
    printf("\n");
    break;
    case 4:
    printf("Nhap thoi gian can tim\n");
    printf("Nhap gio:");gets(checkhour);
    printf("Nhap phut:");gets(checkminte);
    if(checktime(p,checkhour,checkminte)!=NULL)
    {
        printf("%s",checktime(p,checkhour,checkminte)->data.diadiem);
    }
    else
    {
        printf("%s ","Khong tim thay lich su di chuyen");
    }
    case 5:
    break;
    case 6:break;
    default:printf("Nhap lai tu 1->6!\n");
    break;
    }
    }while(choice!=6);
    freee(p);
    return 0;
    //Ho va ten:LE DUOC HOANG MSSV:20194573
}