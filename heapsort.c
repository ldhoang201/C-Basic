#include<stdio.h>
void SWAP(int *a,int *b)
{
    int *temp=a;
    a=b;
    b=temp;
}
void adjust(int list[], int root, int n)
{
    int child, rootkey; int temp;
    temp=list[root]; rootkey=list[root].key;
    child=2*root;
    while (child <= n) {
    if ((child < n) &&

    (list[child].key < list[child+1].key))
    child++;

    if (rootkey > list[child].key) break;
    else {
    list[child/2] = list[child];
    child *= 2;
    }
    }
    list[child/2] = temp;
}
void heapsort(int list[], int n)
{

    int i, j;
    int temp;
    for (i=n/2; i>0; i--) adjust(list, i, n);
    for (i=n-1; i>0; i--) {

    SWAP(list[1], list[i+1], temp);
    adjust(list, 1, i);

    }

}
int main(){
    int a[]={7,2,8,3,5,1,6};
    heapsort(a,7);
    for(int i=0;i<7;i++)
    {
        printf("%3d",a[i]);
    }
}