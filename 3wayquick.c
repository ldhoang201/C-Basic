#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100000
#define element int
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void quicksort(element list[], int left,int right)
{
int pivot, i, j;
element temp;
if (left < right) {
i = left; j = right+1;
pivot = list[left];
do {
do i++; while (list[i] < pivot);
do j--; while (list[j] > pivot);
if (i < j) swap(&list[i], &list[j]);
} while (i < j);
swap(&list[left], &list[j]);
quicksort(list, left, j-1);
quicksort(list, j+1, right);
}
}
void sort(int a[], int l, int r) {
	if (r <= l) return;
	int i = l-1, j = r;
	int p = l-1, q = r;
	while(1)	{
		while (a[++i] < a[r]);
		while (a[r] < a[--j]) if (j == l) break;
		if (i >= j) break;
		swap(&a[i],&a[j]);
		if (a[i]==a[r]) swap(&a[++p],&a[i]);
		if (a[j]==a[r]) swap(&a[--q],&a[j]);
	}
	swap(&a[i],&a[r]);
	j = i - 1;
	i = i + 1;
	for (int k = l ; k <= p; k++) swap(&a[k],&a[j--]);
	for (int k = r-1; k >= q; k--) swap(&a[k],&a[i++]);
	sort(a, l, j);
	sort(a, i, r);
}
int main()
{
    int a[MAX],b[MAX];
    clock_t start,end,begin,last;
    double time_use,time_use1;
    srand(time(NULL));
    for(int v=0;v<MAX;v++)
    {
        a[v]=rand() %10;
    }
    for(int s=0;s<MAX;s++)
    {
        b[s]=rand() %10;
    }
    start=clock();
    quicksort(a,0,MAX-1);
    end=clock();
    time_use = (double)(end - start);
    printf("Time used(2-way partitioning):%.2fs\n\n",time_use);
    begin=clock();
    sort(b,0,MAX-1);
    last=clock();
    time_use = (double)(last - begin);
    printf("Time used(3-way partitioning):%.2fs\n",time_use);
    return 0;
}