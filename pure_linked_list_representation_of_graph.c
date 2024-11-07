#include<stdio.h>
#include<stdlib.h>
typedef struct node_list
{
    int data;
    struct node_list* next;
    struct edge_list* edge;
}nl;
typedef struct edge_list
{
    struct node_list* node;
    struct edge_list* next;
}el;
nl* create_node(nl*sn)
{
    nl*temp=(nl*)malloc(sizeof(nl));
    if(sn==NULL)
    {
        sn=temp;
    }
    else
    {
        nl*p=sn;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=temp;
    }
    temp->next=NULL;
    temp->edge=NULL;
    printf("Enter the value to be stored at the node : ");
    scanf("%d",&temp->data);
    return sn;
}
el* create_edge(el*head,nl*sn)
{
    el*temp=(el*)malloc(sizeof(el));
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        el*p=head;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=temp;
    }
    int val;
    printf("Enter the value of node to be connected : ");
    scanf("%d",&val);
    nl*p=sn;
    while(p->data!=val)
    {
        p=p->next;
    }
    temp->node=p;
    temp->next=NULL;
    return head;
}
void display(nl*sn)
{
    nl*p=sn;
    el*ptr;
    printf("NODE\t\tAdjacent nodes\n");
    while(p!=NULL)
    {
        printf("%d\t\t",p->data);
        ptr=p->edge;
        while(ptr!=NULL)
        {
            printf("%d , ",ptr->node->data);
            ptr=ptr->next;
        }
        printf("\n");
        p=p->next;
    }
}
int main()
{
    nl*sn=NULL,*p=sn;
    int c,n;
    do
    {
        printf("1-Inserting new node \n2Making a new connection\n3-Display\nEnter your choice : ");
        scanf("%d",&c);
        switch (c)
        {
            case 1:
                sn=create_node(sn);
                break;
            case 2:
                printf("Enter the node from which you want to make an edge : ");
                scanf("%d",&n);
                p=sn;
                while(p->data!=n)
                {
                    p=p->next;
                }
                p->edge=create_edge(p->edge,sn);
                break;
            case 3:
                display(sn);
        }
    }while(c>0&&c<4);
    return 0;
}
