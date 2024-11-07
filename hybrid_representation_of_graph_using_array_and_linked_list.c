#include<stdio.h>
#include<stdlib.h>
typedef struct node_list
{
    int data;
    struct edge_list*edge;
}nl;
typedef struct edge_list
{
    struct node_list*node;
    struct edge_list*next;
}el;
void connect(nl **arr)
{
    int a,b,i=0,j=0;
    printf("Enter the node you want to connect : ");
    scanf("%d",&a);
    printf("Enter the node to which you want to connect the node : ");
    scanf("%d",&b);
    while(arr[i]->data!=a)
    {
        i++;
    }
    while(arr[j]->data!=b)
    {
        j++;
    }
    el*temp=(el*)malloc(sizeof(el));
    el*ptr=arr[i]->edge;
    if(ptr==NULL)
    {
        ptr=temp;
        arr[i]->edge=ptr;
    }    
    else
    {
         while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=temp;
    }
    temp->next=NULL;
    temp->node=arr[j];
}
void display(nl **arr,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d\t\t",arr[i]->data);
        el*p=arr[i]->edge;
        while(p!=NULL)
        {
            printf("%d , ",p->node->data);
            p=p->next;
        }
        printf("\n");
    }
}
int main()
{
    nl*arr[100];
    int n,c;
    printf("Enter the no. of nodes in your graph : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        arr[i]=(nl*)malloc(sizeof(nl));
        printf("Enter the data to be stored in node %d : ",i+1);
        scanf("%d",&arr[i]->data);
        arr[i]->edge=NULL;
    }
    printf("Do you want to make connections : 1-YES\n0-NO\nEnter your choice : ");
    scanf("%d",&c);
    while(c)
    {
        connect(arr);
        printf("Do you want to make connections : 1-YES\n0-NO\nEnter your choice : ");
        scanf("%d",&c);
    }
    display(arr,n);
}