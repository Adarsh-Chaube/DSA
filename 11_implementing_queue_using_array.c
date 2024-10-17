#include<stdio.h>
#include<stdlib.h>
#define max 5
void enqueue(int [],int *,int*);
void dequeue(int [],int *,int *);
void traverse(int [],int*,int*);
int isempty(int *,int *);
int main()
{
    int *q,f=-1,r=-1,c,t;
    q=(int *)malloc(max*sizeof(int));
    do
    {
        printf("1-Enqueue\n2-Dequeue\n3-traverse\n4-Check if empty\n");
        printf("Enter the operation you want to perform : ");
        scanf("%d",&c);
        switch (c)
        {
            case 1:
                enqueue(q,&f,&r);
                break;
            case 2:
                dequeue(q,&f,&r);
                break;
            case 3:
                traverse(q,&f,&r);
                break;
            case 4:
                t=isempty(&f,&r);
                (t==1)?printf("The queue is empty."):printf("The queue is not empty.");
        }
    }
    while(c>0 && c<5);
    return 0;
}
void enqueue(int q[max],int *f,int *r)
{
    int a;
    printf("Enter the element to be inserted : ");
    scanf("%d",&a);
    if(*r==max-1)
    {
        printf("The queue is full!!!");
        return;
    }
    else if(*f==-1)
    {
        *r=*f=0;
        q[*r]=a;
    }
    else
    {
        *r=*r+1;
        q[*r]=a;
    }
}
void dequeue(int q[max],int *f,int *r)
{
    if(*f==-1)
    {
        printf("The queue is empty!!!");
        return;
    }
    else if(*f==*r)
    {
        printf("The element %d is deleted.",q[*f]);
        *r=*f=-1;
    }
    else{
        printf("The element %d is deleted.",q[*f]);
        *f=*f+1;
    }
}
void traverse(int q[max],int *f,int *r)
{
    printf("The elements of the array are : \n");
    for(int i=*f;i<=*r;i++)
    {
        printf("%d\t",q[i]);
    }
}
int isempty(int *f,int *r)
{
    if(*f==-1)
        return 1;
    else
        return 0;
}
