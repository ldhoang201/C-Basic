#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} TREE;
TREE* MakeNullTreeNode(TREE *t)
{
    t=NULL;
    return t;
}
TREE* AddTreeNode(TREE *t,int x)
{
    if(t==NULL)
    {
        TREE *p;
        p=(TREE*)malloc(sizeof(TREE));
        p->data=x;
        p->left=NULL;
        p->right=NULL;
        return p;
    }
    else
    {
        if((t->data) > x)
        t->left=AddTreeNode(t->left,x);
        else if((t->data) < x)
        t->right=AddTreeNode(t->right,x);
        return t;
    }  
}
int IsLeaf(TREE* n){
    if(n!=NULL)
    return ((n->left==NULL)&&(n->right==NULL));
else return -1;
}
int count_leaf(TREE *t)
{
    if(t==NULL) return 0;
    if(IsLeaf(t)) return 1;
    return count_leaf(t->left)+count_leaf(t->right);
}
void XoaNode(TREE *t, int data) 
{
    if (t == NULL)
    {
        return;
    }
    else
    {
        if (data < t->data)
        {
            XoaNode(t->left, data); 
        }
        else if (data > t->data)
        {
            XoaNode(t->right, data); 
        }
        else // data == t->data - đã tìm ra cái node cần xóa
        {
            TREE *X = t; // node X là node thế mạng - tí nữa chúng ta sẽ xóa nó
            // nếu như nhánh trái bằng NULL <=> đây là cây có 1 con chính là con phải
            if (t->left == NULL)
            {
                // duyệt sang phải của cái node cần xóa để cập nhật mối liên kết giữa node 
                // cha của node cần xóa với node con của node cần xóa
                t = t->right; 
            }
            else if (t->right == NULL)
            {
                // duyệt sang trái của cái node cần xóa để cập nhật mối liên kết giữa node 
                // cha của node cần xóa với node con của node cần xóa
                t = t->left;
            }
            free(X); // xóa node cần xóa
        }
    }
}
void Traverser_NLR(TREE *t)
{
    if(t != NULL)
    {
        printf("%d\t",t->data);
        Traverser_NLR(t->left);
        Traverser_NLR(t->right);
    }
}
int Search(TREE *t,int x)
{
    if(t == NULL)
    {
        printf("Root rong ne !\n");
    }
    else
    {
        if(t->data > x)
        Search(t->left,x);
        else if(t->data < x)
        Search(t->right,x);
        else 
        return t->data;
    }
}
int main()
{
    TREE *t;
    t=MakeNullTreeNode(t);
    int i,x,a;
    for(i=0;i<6;i++)
    {
        printf("Add Node Tree:");scanf("%d",&x);
        printf("\n");
        t=AddTreeNode(t,x);
    }
    printf("After Traversering:\n");
    Traverser_NLR(t);
    printf("\n");
    printf("Num u wanna delete:");scanf("%d",&a);
    XoaNode(t,a);
    Traverser_NLR(t);
    return 0;
}