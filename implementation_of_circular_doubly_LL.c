#include<stdio.h>
#include<stdlib.h>
typedef struct DoublyLL
{
    struct DoublyLL *prev;
    int info;
    struct DoublyLL* next;
}sd;
void display(sd*head)
{
    sd*p=head;
    if(head==NULL)
        return;
    do
    {
        printf("%d\t",p->info);
        p=p->next;
    }
    while(p!=head);
}
sd * iab(sd*head)
{
    sd* temp=(sd*)malloc(sizeof(sd));
    if(temp==NULL)
    {
        printf("OVERFLOW!!!!\n");
    }
    else if(head==NULL)
    {
        head=temp;
        temp->prev=temp->next=head;
    }
    else
    {
        temp->prev=head->prev;
        temp->next=head;
        head->prev->next=temp;
        head->prev=temp;
        head=temp;
    }
    printf("Enter the info to be stored : ");
    scanf("%d",&temp->info);
    display(head);
    return head;
}
sd *iae(sd*head)
{
    sd* temp=(sd*)malloc(sizeof(sd));
    if(temp==NULL)
    {
        printf("OVERFLOW!!!!\n");
    }
    else if(head==NULL)
    {
        head=temp;
        temp->prev=temp->next=head;
    }
    else
    {
        temp->prev=head->prev;
        temp->next=head;
        head->prev->next=temp;
        head->prev=temp;
    }
    printf("Enter the info to be stored : ");
    scanf("%d",&temp->info);
    display(head);
    return head;
}
sd* iakth(sd* head)
{
    sd * temp=(sd*)malloc(sizeof(sd));
    int n=1,k;
    sd*p=head;
    printf("Enter the position for insertion of node : ");
    scanf("%d",&k);
    while(p!=NULL && p->next!=head)
    {
        n++;
        p=p->next;
    }
    if (temp==NULL)
    {
        printf("OVERFLOW!!!!\n");
    }
    else if(k>n+1)
    {
        printf("Invalid Position!!!!\n");
        return head;
    }
    else if(k==1)
    {
        if(head==NULL)
        {
            head=temp;
            temp->next=temp->prev=head;
        }
        else
        {
            temp->prev=head->prev;
            temp->next=head;
            head->prev->next=temp;
            head->prev=temp;
            head=temp;
        }
    }
    else
    {
        p=head;
        int m=1;
        while(m!=k)
        {
            p=p->next;
            m++;
        }
        p->prev->next=temp;
        temp->prev=p->prev;
        temp->next=p;
        p->prev=temp;
    }
    printf("Enter the info to be stored : ");
    scanf("%d",&temp->info);
    display(head);
    return head;
}
sd* iafternode(sd* head)
{
    sd* temp=(sd*)malloc(sizeof(sd));
    if(temp==NULL)
    {
        printf("UNDERFLOW!!!!\n");
        return head;
    }
    printf("Enter the info of node after which new node is to be inserted : ");
    int i;
    scanf("%d",&i);
    sd* p=head;
    if(p->info==i)
    {
        temp->next=head->next;
        head->next->prev=temp;
        temp->prev=head;
        head->next=temp;
    }
    else{
        do
        {
            p=p->next;
        }
        while(p!=head && p->info!=i);
        if(p==head)
        {
            printf("The node is not found!!!!\n");
            return head;
        }
        else{
            p->next->prev=temp;
            temp->next=p->next;
            temp->prev=p;
            p->next=temp;
        }
    }
    printf("Enter the info to be stored : ");
    scanf("%d",&temp->info);
    display(head);
    return head;
}
sd* dfb(sd*head)
{
    if(head==NULL)
    {
        printf("UNDERFLOW!!!!\n");
    }
    else if(head->prev==head)
    {
        free(head);
        head=NULL;
    }
    else
    {
        sd*p=head;
        head=head->next;
        head->prev=p->prev;
        p->prev->next=head;
        free(p);
    }
    display(head);
    return head;
}
sd* dfe(sd*head)
{
    if(head==NULL)
    {
        printf("UNDERFLOW!!!!\n");
    }
    else if(head->prev==head)
    {
        free(head);
        head=NULL;
    }
    else
    {
        sd*p=head->prev;
        p->prev->next=head;
        head->prev=p->prev;
        free(p);
    }
    display(head);
    return head;
}
sd* dfp(sd*head)
{
    sd*p=head;
    int n=1,k;
    while(p->next!=head)
    {
        n++;
        p=p->next;
    }
    printf("Enter the position from which node is to be deleted : ");
    scanf("%d",&k);
    if(k>n)
    {
        printf("Invalid Position!!!!\n");
    }
    else if(k==1)
    {
        sd*p=head;
        head->prev->next=head->next;
        head->next->prev=head->prev;
        head=head->next;
        free(p);
    }
    else{
        int m=1;
        p=head;
        while(m!=k)
        {
            p=p->next;
            m++;
        }
        p->prev->next=p->next;
        p->next->prev=p->prev;
        free(p);
    }
    display(head);
    return head;
}
sd* dbn(sd*head)
{
    int i;
    printf("Enter the info of node before which node has to be deleted : ");
    scanf("%d",&i);
    if(head->next->info==i)
    {
        sd*p=head;
        head->next->prev=head->prev;
        head->prev->next=head->next;
        head=head->next;
        free(p);
    }
    else
    {
        sd *p=head->next;
        while(p->next->info!=i && p!=head)
        {
            p=p->next;
        }
        if(p==head)
        {
            printf("The given info is not found!!!!\n");
        }
        else
        {
            p->prev->next=p->next;
            p->next->prev=p->prev;
            free(p);
        }
    }
    display(head);
    return head;
}
int main()
{
    sd*head=NULL;
    int c;
    do{
        printf("1-Insert at beginning\n2-Insert at end\n3-Insert at given position\n4-Insert after a node\n5-Delete from beginning\n6-Delete from end\n7-Delete from given position\n8-Delete node before a given node\n9-Display\nEnter your choice : ");
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
                head=iakth(head);
                break;
            case 4:
                head=iafternode(head);
                break;
            case 5:
                head=dfb(head);
                break;
            case 6:
                head=dfe(head);
                break;
            case 7:
                head=dfp(head);
                break;
            case 8:
                head=dbn(head);
                break;
            case 9:
                display(head);
        }
    }
    while(c>0 && c<10);
    return 0;
}