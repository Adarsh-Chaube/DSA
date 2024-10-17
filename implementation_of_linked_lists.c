#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int info;
    struct node * next;
}sn;
void display(sn * head)
{
    sn*p=head;
    printf("The elements of the linked list are : \n");
    while(p!=NULL)
    {
        printf("%d\t",p->info);
        p=p->next;
    }
    printf("\n");
}
sn* iab(sn*head)
{
    sn *temp=(sn*)malloc(sizeof(sn));
    if(temp==NULL)
    {
        printf("OVERFLOW!!!!\n");
        return head;
    }
    printf("Enter the value to be stored in new node : ");
    int a;
    scanf("%d",&a);
    temp->info=a;
    if(head==NULL)
    {
        temp->next=head;
        head=temp;
    }
    else
    {
        temp->next=head;
        head=temp;
    }
    display(head);
    return head;
}
sn* iae(sn*head)
{
    sn*p=head;
    sn *temp=(sn*)malloc(sizeof(sn));
    if(temp==NULL)
    {
        printf("OVERFLOW!!!!\n");
        return head;
    }
    printf("Enter the value to be stored in new node : ");
    scanf("%d",&temp->info);
    if(head==NULL)
    {
        temp->next=head;
        head=temp;
    }
    else
    {
        while(p->next!=NULL)
        {
            p=p->next;
        }
        temp->next=NULL;
        p->next=temp;
    }
    display(head);
    return head;
}
sn* ibk(sn*head)
{
    sn*p=head;
    sn *temp=(sn*)malloc(sizeof(sn));
    if(temp==NULL)
    {
        printf("OVERFLOW!!!!\n");
        return head;
    }
    printf("Enter the value to be stored in new node : ");
    scanf("%d",&temp->info);
    printf("Enter the position of node before which you want to insert new node : ");
    int k;
    scanf("%d",&k);
    for(int i=1;i<k-1;i++)
    {
        p=p->next;
    }
    temp->next=p->next;
    p->next=temp;
    display(head);
    return head;
}
sn* iak(sn*head)
{
    sn*p=head;
    sn *temp=(sn*)malloc(sizeof(sn));
    if(temp==NULL)
    {
        printf("OVERFLOW!!!!\n");
        return head;
    }
    printf("Enter the value to be stored in new node : ");
    scanf("%d",&temp->info);
    printf("Enter the position of node after which you want to insert new node : ");
    int k;
    scanf("%d",&k);
    for(int i=1;i<k;i++)
    {
        p=p->next;
    }
    temp->next=p->next;
    p->next=temp;
    display(head);
    return head;
}
sn* iatk(sn*head)
{
    head=ibk(head);
    return head;
}
sn* dfb(sn* head)
{
    sn*p=head;
    if(head==NULL)
    {
        printf("UNDERFLOW!!!");
    }
    else
    {
        head=head->next;
        free(p);
    }
    display(head);
    return head;
}
sn* dfe(sn*head)
{
    sn*p=head,*p2;
    if(head==NULL)
    {
        printf("UNDERFLOW!!!!\n");
    }
    else if(head->next==NULL)
    {
        free(head);
        head=NULL;
    }
    else
    {
        while(p->next!=NULL)
        {
            p2=p;
            p=p->next;
        }
        p2->next=NULL;
        free(p);
    }
    display(head);
    return head;
}
sn* dfk(sn*head)
{
    sn *p=head,*p1;
    if(head==NULL)
    {
        printf("UNDERFLOW!!!\n");
        return  head;
    }
    printf("Enter the position k : ");
    int k;
    scanf("%d",&k);
    for(int i=1;i<k-1;i++)
    {
        p=p->next;
    }
    p1=p->next;
    p->next=p1->next;
    free(p1);
    display(head);
    return head;
}
int main()
{
    sn*head=NULL;
    int c;
    do
    {
        printf("1-Insertion at beginning\n2-Insertion at end\n3-Insertion before kth position\n4-Insertion after kth position\n5-Insertion at kth position\n6-Deletion from beginning\n7-Deletion from end\n8-Deletion from kth position\nAny other digit for exiting\nEnter your choice : ");
        scanf("%d",&c);
        switch (c)
        {
            case 1:
                head=iab(head);
                break;
            case 2:
                head=iae(head);
                break;
            case 3:
                head=ibk(head);
                break;
            case 4:
                head=iak(head);
                break;
            case 5:
                head=iatk(head);
                break;
            case 6:
                head=dfb(head);
                break;
            case 7:
                head=dfe(head);
                break;
            case 8:
                head=dfk(head);
                break;
        }
    }
    while(c>0 && c<9);
    return 0;
}