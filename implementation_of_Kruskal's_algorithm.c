#include<stdio.h>
#include<stdlib.h>
typedef struct graph
{
    int src;
    int dst;
    int weight;
    struct graph*next;
}graph;
typedef struct parent_matrix
{
    int node;
    int org;
}pm;
void display(graph*head)
{
    graph *p=head;
    printf("The minimal spanning tree is : \nSource---Destination : \tWeight\n");
    while(p!=NULL)
    {
        printf("%d---%d :\t\t%d\n",p->src,p->dst,p->weight);
        p=p->next;
    }
}
int main()
{
    graph*start=NULL;
    int n=0,k=0;
    char c;
    printf("Enter the no. of nodes in the graph : ");
    scanf("%d",&n);
    pm arr[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter the value of the node : ");
        scanf("%d",&arr[i].node);
        arr[i].org=arr[i].node;
    }
    printf("INSERT EDGES in ascending order of their weights \n");
    printf("Enter Y for making an edge and N otherwise : ");
    scanf(" %c",&c);
    while(c=='Y'||c=='y')
    {
        graph*temp=(graph*)malloc(sizeof(graph));
        printf("Enter the source of edge : ");
        scanf("%d",&temp->src);
        printf("Enter the destination : ");
        scanf("%d",&temp->dst);
        printf("Enter the weight of the edge : ");
        scanf("%d",&temp->weight);
        if(start==NULL)
        {
            start=temp;
        }
        else
        {
            graph*p=start;
            while(p->next!=NULL)
            {
                p=p->next;
            }
            p->next=temp;
        }
        temp->next=NULL;
        printf("Enter Y for inserting node and N otherwise : ");
        scanf(" %c",&c);
    }
    graph*p=start;
    graph*ptr=NULL;
    while(k<n-1)
    {
        int i=0,j=0;
        while(arr[i].node!=p->src)
        {
            i++;
        }
        while(arr[j].node!=p->dst)
        {
            j++;
        }
        if(arr[i].org==arr[j].org)
        {
            ptr->next=p->next;
            free(p);
            p=ptr->next;
            continue;
        }    
        else
        {
            arr[j].org=arr[i].org;
            k++;
            ptr=p;
            p=p->next;
        }
    }
    ptr->next=NULL;
    while(p!=NULL)
    {
        ptr=p;
        p=p->next;
        free(ptr);
    }
    display(start);
    return 0;
}