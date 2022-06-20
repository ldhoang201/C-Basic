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
TREE* deleteNode(TREE* root, int key)
{
    if (root == NULL)
        return root;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            TREE* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            TREE* temp = root->left;
            free(root);
            return temp;
        }
        TREE* current = root->right;
    while (current && current->left != NULL)
        current = current->left;
        TREE* temp = current;
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
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
int count_node(TREE *t)
{
    if(t==NULL) return 0;
    return 1+count_node(t->right)+count_node(t->left);
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
int depth(TREE *tree){
    if(tree==NULL) return 0;
    int ld = depth(tree->left);
    int rd = depth(tree->right);
    return 1+(ld>rd ? ld : rd);
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
    //printf("Hight of tree:%d\n",depth(t));
    //printf("Num u wanna delete:");scanf("%d",&a);
    //deleteNode(t,a);
    //Traverser_NLR(t);
    printf("Count Node:%d\n",count_node(t));
    return 0;
}
