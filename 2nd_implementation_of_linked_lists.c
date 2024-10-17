#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int info;
    struct node *next;
}sn;
void display(sn*head)
{
    sn*p=head;
    while(p!=NULL)
    {
        printf("%d\t",p->info);
        p=p->next;
    }
    printf("\n");
}
sn* iab(sn*head)
{
    sn* temp=(sn*)malloc(sizeof(sn));
    if(temp==NULL)
    {
        printf("OVERFLOW!!!!\n");
        return head;
    }
    printf("Enter the info to be stored at the new node : ");
    scanf("%d",&temp->info);
    temp->next=head;
    head=temp;
    display(head);
    return head;
}
sn *iae(sn*head)
{
    sn* temp=(sn*)malloc(sizeof(sn));
    if(temp==NULL)
    {
        printf("OVERFLOW!!!!\n");
        return head;
    }
    printf("Enter the info to be stored at the new node : ");
    scanf("%d",&temp->info);
    if(head==NULL)
    {
        temp->next=head;
        head=temp;
    }
    else
    {
        sn *p=head;
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
sn* iak(sn*head)
{
    sn* temp=(sn*)malloc(sizeof(sn));
    if(temp==NULL)
    {
        printf("OVERFLOW!!!!\n");
        return head;
    }
    printf("Enter the info to be stored at the new node : ");
    scanf("%d",&temp->info);
    printf("Enter the info of node before which new node is to be inserted : ");
    int k;
    scanf("%d",&k);
    if(head->info==k)
    {
        temp->next=head;
        head=temp;
    }
    else
    {
        sn* p=head;
        while((p->next)->info!=k && p->next!=NULL)
        {
            p=p->next;
        }
        if(p->next==NULL)
        {
            printf("The given info is not found in the linked list.!!!\n");
            free(temp);
        }
        else{
            temp->next=p->next;
            p->next=temp;
        }
    }
    display(head);
    return head;
}
sn *dfb(sn*head)
{
    if(head==NULL)
    {
        printf("UNDERFFLOW!!!!\n");
        return NULL;
    }
    else
    {
        sn*p=head;
        head=head->next;
        free(p);
    }
    display(head);
    return head;
}
sn* dfe(sn*head)
{
    if(head==NULL)
    {
        printf("UNDERFLOW!!!!\n");
        return NULL;
    }
    else if(head->next==NULL)
    {
        free(head);
        head=NULL;
    }
    else
    {
        sn*p=head,*p1;
        while(p->next!=NULL)
        {
            p1=p;
            p=p->next;
        }
        free(p);
        p1->next=NULL;
    }
    display(head);
    return head;
}
sn* dfk(sn*head)
{
    if(head==NULL)
    {
        printf("UNDERFLOW!!!!\n");
        return NULL;
    }
    int k;
    printf("Enter the info of node that needs to be deleted : ");
    scanf("%d",&k);
    if(head->info==k)
    {
        sn*p=head;
        head=head->next;
        free(p);
    }
    else
    {
        sn*p=head,*p1;
        while(p->info!=k && p->next!=NULL)
        {
            p1=p;
            p=p->next;
        }
        if(p->next==NULL && p->info!=k)
        {
            printf("The given info is not found in the list!!!!\n");
        }
        else
        {
            p1->next=p->next;
            free(p);
        }
    }
    display(head);
    return head;
}
sn* reverse(sn*head)
{
    /*sn* p1=NULL,*p2=head,*p3=NULL;
    while(p2!=NULL)
    {
        p3=p2->next;
        p2->next=p1;
        p1=p2;
        p2=p3;
    }
    head=p1;*/
    /*Another approach only using 2 pointers*/
    sn* p1=head,*p2=head->next;head->next=NULL;
    while(p2!=NULL)
    {
        head=p2;
        p2=p2->next;
        head->next=p1;
        p1=head;
    }
    display(head);
    return head;
}
sn* rotate(sn*head)
{
    int n;
    printf("Enter the no. of rotations : ");
    scanf("%d",&n);
    sn*p=head;
    int l=0;
    while(p!=NULL)
    {
        p=p->next;
        l++;
    }
    n=n%l;
    for(int i=0;i<n;i++)
    {
        sn*p=head,*p1;
        while(p->next!=NULL)
        {
            p1=p;
            p=p->next;
        }
        p1->next=NULL;
        p->next=head;
        head=p;
    }
    display(head);
    return head;
}
sn* delnthfromlast(sn*head)
{
    int n,l=0;
    printf("Enter the value of n : ");
    scanf("%d",&n);
    sn*p=head,*p1;
    while(p!=NULL)
    {
        p=p->next;
        l++;
    }
    p=head;
    if(l==n)
    {
        head=head->next;
        free(p);
    }
    else 
    {
        for(int i=1;i!=(l-n+1);i++)
        {
            p1=p;
            p=p->next;
        }
        p1->next=p->next;
        free(p);
    }
    display(head);
    return head;
}
sn* removeduplicate(sn*head)
{
    sn*p=head;
    while(p!=NULL)
    {
        sn*p1=p->next,*p2=p;
        while(p1!=NULL)
        {
            if(p->info==p1->info)
            {
                p2->next=p1->next;
                free(p1);
                p1=p2;
            }
            p2=p1;
            p1=p1->next;
        }
        p=p->next;
    }
    display(head);
    return head;
}
void printReverse(sn* head)
{
    if(head->next!=NULL)
    {
        printReverse(head->next);
        printf("%d\t",head->info);
    }
    else
        printf("%d\t",head->info);
    
    
}
sn* check_palindrome(sn*head,sn*ptr)
{
    if(head==NULL || ptr==NULL)
        return ptr;
    ptr=check_palindrome(head->next,ptr);
    if(head->info==ptr->info)
    {
        if(ptr->next==NULL)
            ptr=head;
        else
            ptr=ptr->next;
        return ptr;
    }
    else
    {
        return NULL;
    }    
}
int main()
{
    sn*head=NULL,*ptr;
    int c;
    do{
        printf("1-Insert at beginning\n2-Insert at end\n3-Insert before given info\n4-Delete from beginning\n5-Delete from end\n6-Delete the node having given info\n7-Reverse the list\n8-Rotate the list\nEnter any other digit for exiting\nEnter your choice : ");
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
                head=iak(head);
                break;
            case 4:
                head=dfb(head);
                break;
            case 5:
                head=dfe(head);
                break;
            case 6:
                head=dfk(head);
                break;
            case 7:
                head=reverse(head);
                break;
            case 8:
                head=rotate(head);
                break;
            case 9:
                head=delnthfromlast(head);
                break;
            case 10:
                head=removeduplicate(head);
                break;
            case 11:
                printf("The reverse of the linked list is : \n");
                printReverse(head);
            case 12:
                ptr=check_palindrome(head,head);
                if(ptr==NULL)
                    printf("The list is not palindrome.");
                else
                    printf("The list is palindrome.");
        }
    }
    while(c>0&&c<13);
    return 0;
}