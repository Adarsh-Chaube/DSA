#include<stdio.h>
#include<stdlib.h>
#define max 7
void enqueuef(int q[],int*f,int*r)
{
    if(*f==(*r+1)%max)
    {
        printf("OVERFLOW!!!\n");
        return;
    }
    int a;
    printf("Enter the item to be inserted : ");
    scanf("%d",&a);
    if(*f==-1)
    {
        *f=*r=0;
    }
    else
    {
        *f=((*f-1)+max)%max;
    }
    q[*f]=a;
}
void enqueuer(int q[],int*f,int*r)
{
    if(*f==(*r+1)%max)
    {
        printf("OVERFLOW!!!!\n");
        return;
    }
    int a;
    printf("Enter the element to be inserted : ");
    scanf("%d",&a);
    if(*f==-1)
    {
        *f=*r=1;
    }
    else
    {
        *r=(*r+1)%max;
    }
    q[*r]=a;
}
void dequeuef(int q[],int*f,int*r)
{
    int a;
    if(*f==-1)
    {
        printf("UNDERFLOW!!!!!\n");
        return;
    }
    else if(*f==*r)
    {
        a=q[*f];
        *f=*r=-1;
    }
    else
    {
        a=q[*f];
        *f=(*f+1)%max;
    }
    printf("The element %d is dequeued from front.\n",a);
}
void dequeuer(int q[],int*f,int*r)
{
    int a;
    if(*r==-1)
    {
        printf("UNDERFLOW!!!!\n");
        return;
    }
    if(*r==*f)
    {
        a=q[*r];
        *r=*f=-1;
    }
    else
    {
        a=q[*r];
        *r=((*r-1)%max +max)%max;
    }
    printf("The element %d is dequeued from rear.\n",a);
}
void traverse(int q[],int*f,int*r)
{
    printf("The elements of the queue are : \n");
    for(int i=*f;i!=*r;i=(i+1)%max)
    {
        printf("%d\t",q[i]);
    }
    printf("%d\n",q[*r]);
}
int main()
{
    int *q,c,f=-1,r=-1;
    q=(int *)malloc(sizeof(int)*max);
    do
    {
        printf("1-enqueue at front\n2-enqueue at rear\n3-dequeue at front\n4-dequeue at rear\n5-traverse\nEnter any other number for exiting\nEnter your choice :");
        scanf("%d",&c);
        switch (c)
        {
            case 1:
                enqueuef(q,&f,&r);
                break;
            case 2:
                enqueuer(q,&f,&r);
                break;
            case 3:
                dequeuef(q,&f,&r);
                break;
            case 4:
                dequeuer(q,&f,&r);
                break;
            case 5:
                traverse(q,&f,&r);
                break;
        }
    }
    while(c>0&&c<6);
}