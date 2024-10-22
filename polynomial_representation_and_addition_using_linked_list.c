#include<stdio.h>
#include<stdlib.h>
typedef struct polynomial
{
    int pow;
    int coeff;
    struct polynomial *next;
}poly;
void display(poly*head)
{
    poly*p=head;
    printf("The polynomials after adding are : \n");
    while(p!=NULL)
    {
        printf("%dx^%d\t",p->coeff,p->pow);
        if(p->pow!=0)
            printf("+\t");
        p=p->next;
    }
    printf("\n");
}
poly* create(poly*head)
{
    poly*temp=(poly*)malloc(sizeof(poly));
    if(temp==NULL)
    {
            printf("OVERFLOW!!!!\n");
            return NULL;
    }
    head=temp;
    do
    {
        printf("Enter the power of variable : ");
        scanf("%d",&temp->pow);
        printf("Enter the coefficient : ");
        scanf("%d",&temp->coeff);
        poly *p=temp;
        if(p->pow!=0)
        {
            temp=(poly*)malloc(sizeof(poly));
            if(temp==NULL)
            {
                    printf("OVERFLOW!!!!\n");
                    return NULL;
            }
            p->next=temp;
        }
    }while(temp->pow!=0);
    temp->next=NULL;
    return head;
}
void add(poly*h1,poly*h2)
{
    poly*head=(poly*)malloc(sizeof(poly));
    poly*temp=head;
    while(h1 && h2)
    {
        if(h1->pow>h2->pow)
        {
            temp->pow=h1->pow;
            temp->coeff=h1->coeff;
            h1=h1->next;
        }
        else if(h2->pow>h1->pow)
        {
            temp->pow=h2->pow;
            temp->coeff=h2->coeff;
            h2=h2->next;
        }
        else
        {
            temp->pow=h1->pow;
            temp->coeff=h1->coeff+h2->coeff;
            h1=h1->next;
            h2=h2->next;
        }
        if(h1 || h2)
        {
            temp->next=(poly*)malloc(sizeof(poly));
            temp=temp->next;
        }
    }
    while(h1 || h2)
    {
        if(h1)
        {
            temp->pow=h1->pow;
            temp->coeff=h1->coeff;
            h1=h1->next;
        }
        if(h2)
        {
            temp->pow=h2->pow;
            temp->coeff=h2->coeff;
            h2=h2->next;
        }
        if(h1 || h2)
        {
            temp->next=(poly*)malloc(sizeof(poly));
            temp=temp->next;
        }
    }
    temp->next=NULL;
    display(head);
}
int main()
{
    poly*h1=NULL,*h2=NULL,*p1,*p2;
    printf("Enter the first polynomial : \n");
    h1=create(h1);
    printf("Enter the second polynomial : \n");
    h2=create(h2);
    add(h1,h2);
    return 0;
}