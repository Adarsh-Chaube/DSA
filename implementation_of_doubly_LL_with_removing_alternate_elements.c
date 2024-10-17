#include<stdio.h>
#include<stdlib.h>
typedef struct doublyNode
{
    struct doublyNode* prev;
    int info;
    struct doublyNode* next;
}sd;
void display(sd* head)
{
    sd*p=head;
    while(p!=NULL)
    {
        printf("%d\t",p->info);
        p=p->next;
    }
    printf("\n");
}
sd* iab(sd*head)
{
    sd*temp=(sd*)malloc(sizeof(sd));
    if(temp==NULL)
    {
        printf("OVERFLOW!!!!\n");
        return head;
    }
    else if(head==NULL)
    {
        head=temp;
        temp->next=temp->prev=NULL;
    }
    else
    {
        temp->next=head;
        head->prev=temp;
        temp->prev=NULL;
        head=temp;
    }
    printf("Enter the info for new node : ");
    scanf("%d",&temp->info);
    display(head);
    return head;
}
sd* iae(sd* head)
{
    sd* temp=(sd*)malloc(sizeof(sd));
    if(temp==NULL)
    {
        printf("OVERFLOW!!!\n");
        return head;
    }
    else if(head==NULL)
    {
        head=temp;
        temp->next=temp->prev=NULL;
    }
    else
    {
        sd*p=head;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=temp;
        temp->prev=p;
        temp->next=NULL;
    }
    printf("Enter the info for new node : ");
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
    else
    {
        sd*p=head;
        head=head->next;
        head->prev=NULL;
        free(p);
    }
    display(head);
    return head;
}
sd* dfe(sd* head)
{
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
        sd* p=head,*p1;
        while(p->next!=NULL)
        {
            p1=p;
            p=p->next;
        }
        p1->next=NULL;
        free(p);
    }
    display(head);
    return head;
}
sd* remalt(sd*head)
{
    printf("1-for removing odd elements\n2-for removing even position elements\n Enter your choice : ");
    int c;
    scanf("%d",&c);
    sd*p,*p1;
    p=(c==1)?head:head->next;
    if(p==head)
    {
        head=head->next;
        head->prev=NULL;
        p1=p;
        p=p->next;
        free(p1);
    }
    else
    {
        p=head;
    }
    while(p!=NULL && p->next!=NULL)
    {
        p=p->next;
        p->prev->next=p->next;
        if(p->next!=NULL)
            p->next->prev=p->prev;
        p1=p;
        free(p);
        p=p1->next;
    }
    display(head);
    return head;
}
int main()
{
    sd* head=NULL;
    int c;
    do
    {
        printf("1-Insert at beg\n2-Insert at end\n3-Delete from beginning\n4-Delete from end\n5-Remove Alternate elements\nEnter your choice : ");
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
                head=dfb(head);
                break;
            case 4:
                head=dfe(head);
                break;
            case 5:
                head=remalt(head);
                break;
        }
    }
    while(c>0 && c<6);
    return 0;
}