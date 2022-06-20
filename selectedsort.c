#include<stdio.h>
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
    // Di chuyển ranh giới của mảng đã sắp xếp và chưa sắp xếp
    for (i = 0; i < n-1; i++)
    {
    // Tìm phần tử nhỏ nhất trong mảng chưa sắp xếp
    min_idx = i;
    for (j = i+1; j < n; j++)
        if (arr[j] > arr[min_idx])
        min_idx = j;
 
    // Đổi chỗ phần tử nhỏ nhất với phần tử đầu tiên
        swap(&arr[min_idx],&arr[i]);
        printf("%d\n",i);
    }
}
int main(){
    int a[]={27,40,-7,5,57};
    selectionSort(a,5);
    for(int i=0;i<5;i++)
    {
        printf("%3d",a[i]);
    }
    return 0;
}