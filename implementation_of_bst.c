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
void min_value(tree*root)
{
    tree*p=root;
    while(p->left!=NULL)
    {
        p=p->left;
    }
    printf("The minimun value is : %d\n",p->info);
}
void max_value(tree *root)
{
    tree*p=root;
    while(p->right!=NULL)
    {
        p=p->right;
    }
    printf("The maximum value is : %d\n",p->info);
}
void search(tree*root)
{
    printf("Enter the number to be searched : ");
    int v;
    scanf("%d",&v);
    tree*p=root;
    while(p!=NULL)
    {
        if(v>p->info)
        {
            p=p->right;
        }
        else if(v==p->info)
        {
            printf("The number is found.\n");
            return;
        }
        else
        {
            p=p->left;
        }
    }
    printf("The number is not found.\n");
}
int main()
{
    tree *root=NULL;
    int c,v,count=0,cl=0,cs=0;
    do{
        printf("1-Insert element in BST\n2-Inorder traversal of BST\n3-Preorder traversal of BST\n4-Postorder traversal of BST\n5-Count the number of nodes\n6-Count number of leaf nodes\n7-Count number of nodes with single child\n8-Print minimum value\n9-Print maximum value\nEnter your choice : ");
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
                break;
            case 8:
                min_value(root);
                break;
            case 9:
                max_value(root);
                break;
            case 10:
                search(root);
                break;
        }
    }while(c>0&&c<11);
    return 0;
}
