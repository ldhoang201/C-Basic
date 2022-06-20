#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int ar1[10000000],ar2[10000000],ar3[10000000];
int *creatArray()
{
    srand(time(NULL));
    for (int i = 0; i < 10000000; i++)
    {
        ar1[i]=rand();
        ar2[i]=ar1[i];
        ar3[i]=ar1[i];
    }
}
int compare (void * a,void * b)
{
  return ( *(int*)a - *(int*)b );
}
void swap(void* v1, void* v2, int size)
{
    void *buffer=malloc(size);
    memcpy(buffer, v1, size);
    memcpy(v1, v2, size);
    memcpy(v2, buffer, size);
    free(buffer);
}
void sort2way(void* v, int size, int left, int right,int (*comp)(void*, void*))
{
    void *vt, *v3;
    int i, last, mid = (left + right) / 2;
    if (left >= right)
        return;
    void* vl = (char*)(v + (left * size));
    void* vr = (char*)(v + (mid * size));
    swap(vl, vr, size);
    last = left;
    for (i = left + 1; i <= right; i++) {
        vt = (char*)(v + (i * size));
        if ((*comp)(vl, vt) > 0) {
            ++last;
            v3 = (char*)(v + (last * size));
            swap(vt, v3, size);
        }
    }
    v3 = (char*)(v + (last * size));
    swap(vl, v3, size);
    sort2way(v, size, left, last - 1, comp);
    sort2way(v, size, last + 1, right, comp);
}
void exch(void* a, int size, int i,int r)
{
    void *buffer=malloc(size);
    memcpy(buffer, a+size*i, size);
    memcpy(a+size*i, a+size*r, size);
    memcpy(a+size*r, buffer, size);
    free(buffer);
}
void sort3way(void * a, int size, int l, int r,int(*compare)(void*,void *)) {
    if (r <= l) return;
    int i = l - 1, j = r;
    int p = l - 1, q = r;
    while (1) {
      while (compare((char*)a+(++i)*size,(char*) a +r*size) < 0);
      while (compare((char*)a+r*size,(char*) a +(--j)*size) < 0)
        if (j == l) break;
      if (i >= j) break;
      exch(a, size, i, j);
      if (compare((char*)a+i*size,(char*)a+r*size)==0)
        exch(a,size,++p,i);
      if (compare((char*)a+j*size,(char*)a+r*size)==0)
        exch(a,size,--q,j);
    }
    exch(a, size, i, r);
    j = i - 1;
    i = i + 1;
    for (int k = l; k <= p; k++) exch(a, size, k, j--);
    for (int k = r - 1; k >= q; k--) exch(a, size, k, i++);
    sort3way(a, size, l, j, compare);
    sort3way(a, size, i, r, compare);
    }
int main()
{
    clock_t dau, cuoi;
    double t1, t2;
    creatArray();
    dau = clock();
    sort2way(ar1,sizeof(int), 0, 10000000,compare);
    cuoi = clock();
    t1 = (double)(cuoi - dau) / CLOCKS_PER_SEC;
    printf("sort2way: %f\n", t1);
    dau = clock();
    sort3way(ar2,sizeof(int), 0, 10000000,compare);
    cuoi = clock();
    t2 = (double)(cuoi - dau) / CLOCKS_PER_SEC;
    printf("sort3way: %f\n", t2);
    dau = clock();
    qsort(ar3,10000000,sizeof(int),compare);
    cuoi = clock();
    t2 = (double)(cuoi - dau) / CLOCKS_PER_SEC;
    printf("qsort: %f\n", t2);
    system("PAUSE");
}
