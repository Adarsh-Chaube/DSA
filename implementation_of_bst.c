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
int main()
{
    tree *root=NULL;
    int c,v;
    do{
        printf("1-Insert element in BST\n2-Inorder traversal of BST\n3-Preorder traversal of BST\n4-Postorder traversal of BST\nEnter your choice : ");
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
        }
    }while(c>0&&c<5);
    return 0;
}