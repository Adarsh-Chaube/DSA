#include<stdio.h>
#include<stdlib.h>
#define maxsize 100
void push(int *,int *);
void pop(int *,int *);
void peek(int *,int *);
void display(int *,int *);
int main()
{
    int *stack,top=-1,c;
    stack=(int *)malloc(maxsize*sizeof(int));
    do
    {
        printf("Enter the operation you want to perform : 1-PUSH\n2-POP\n3-PEEK\n4-DISPALY\n5-No operation to be performed");
        scanf("%d",&c);
        switch (c)
        {
            case 1:
                push(stack,&top);
                break;
            case 2:
                pop(stack,&top);
                break;
            case 3:
                peek(stack,&top);
                break;
            case 4:
                display(stack,&top);
                break;
            case 5:
                break;
        }
    }
    while(c>0 && c<5);
    return 0;
}
void push(int * stack, int * top)
{
    if(*top==maxsize)
    {
        printf("The stack is FULL!!!!");
        return;
    }
    int a;
    printf("Enter the element to be pushed into stack : ");
    scanf("%d",&a);
    *top=(*top)+1;
    stack[*top]=a;//*(stack+*top)=a;
}
void pop(int *stack,int *top)
{
    if(*top==-1)
    {
        printf("The stack is empty!!!!");
        return;
    }
    *top=(*top)-1;
}
void peek(int *stack,int *top)
{
    if(*top==-1)
    {
        printf("The stack is empty!!!!");
        return;
    }
    printf("The topmost element is : %d",*(stack+*top));
}
void display(int * stack,int *top)
{
    if(*top==-1)
    {
        printf("The stack is empty!!!!");
        return;
    }
    int l=*top;
    printf("The elements of the stack are : \n");
    while(l>=0)
    {
        printf("%d\t",*(stack+l));
        l--;
    }
}