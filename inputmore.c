int main(void) {
  int arr[10],brr[10];
  int tong1,tong2;
  int n;
  tong1=tong2=0;
  int i,j,x;
  int choice;
  do{
  printf("Ban chon:");scanf("%d",&choice);
  switch(choice)
  {
  case 1:
  do{
    tong1=tong2;
    printf("Nhap so sinh vien:");scanf("%d",&n);
    if(tong2+n>20) printf("Gia tri nhap k hop le\n");
    else tong2=tong2+n;
  }while(tong2>20);
  for(i=tong1;i<tong2;i++)
  {
    printf("Nhap a[%d]:",i);scanf("%d",&arr[i]);
  } break;
  case 2:
  for(i=0;i<tong2;i++)
  {
    printf("%d\n",arr[i]);
  }
  default:break;
  }
  }while(choice!=3);
  return 0;
}