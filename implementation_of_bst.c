#include<stdio.h>
#include<stdlib.h>
typedef struct tree
{
    struct tree*left;
    int info;
    struct tree*right;
}tree;
void insert(tree** root,int v)
{
    if(*root==NULL)
    {
        tree*temp=(tree*)malloc(sizeof(tree));
        temp->info=v;
        temp->left=temp->right=NULL;
        *root=temp;
    }
    else if(v>((*root)->info))
    {
        insert(&((*root)->right),v);
    }
    else
    {
        insert(&((*root)->left),v);
    }
}
void inorder(tree *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d\t",root->info);
        inorder(root->right);
    }
}
void preorder(tree *root)
{
    if(root!=NULL)
    {
        printf("%d\t",root->info);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(tree *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d\t",root->info);
    }
}
void count_nodes(tree *root,int*c)
{
    if(root!=NULL)
    {
        (*c)++;
        count_nodes(root->left,c);
        count_nodes(root->right,c);
    }
}
void count_leaf(tree *root,int*c)
{
    if(root!=NULL)
    {
        if(root->left==NULL && root->right==NULL)
            (*c)++;
        count_leaf(root->left,c);
        count_leaf(root->right,c);
    }
}
void count_single(tree *root,int*c)
{
    if(root!=NULL)
    {
        if(root->left==NULL ^ root->right==NULL)
            (*c)++;
        count_single(root->left,c);
        count_single(root->right,c);
    }
}
int main()
{
    tree *root=NULL;
    int c,v,count=0,cl=0,cs=0;
    do{
        printf("1-Insert element in BST\n2-Inorder traversal of BST\n3-Preorder traversal of BST\n4-Postorder traversal of BST\n5-Count the number of nodes\n6-Count number of leaf nodes\n7-Count number of nodes with single child\nEnter your choice : ");
        scanf("%d",&c);
        switch (c)
        {
            case (1):
                printf("Enter the element to be inserted : ");
                scanf("%d",&v);
                insert(&root,v);
                break;
            case (2):
                printf("The inorder traversal of the BST is : ");
                inorder(root);
                break;
            case (3):
                printf("The preorder traversal of the BST is : ");
                preorder(root);
                break;
            case (4):
                printf("The postorder traversal of the BST is : ");
                postorder(root);
                break;
            case 5:
                count=0;
                count_nodes(root,&count);
                printf("The total no. of nodes are : %d\n",count);
                break;
            case 6:
                cl=0;
                count_leaf(root,&cl);
                printf("The total no. of leaf nodes are : %d\n",cl);
                break;
            case 7:
                cs=0;
                count_single(root,&cs);
                printf("The total no. of nodes with single child are : %d\n",cs);
        }
    }while(c>0&&c<8);
    return 0;
}
