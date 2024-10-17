#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
bool issalnum(char a)
{
    if((a>47 && a<58)||(a>64 && a<91)||(a>96 && a<123))
        return true;
    return false;
}
int pre(char a)
{
    if(a=='^')
        return 3;
    else if(a=='*' || a=='/')
        return 2;
    else if(a=='+' || a=='-')
        return 1;
    else
        return 0;
}
int main()
{
    char arr[100],*stack,*postfix;
    stack=(char*)malloc(100*sizeof(char));
    postfix=(char*)malloc(100*sizeof(char));
    printf("Enter the infix expression to be converted : ");
    scanf("%[^\n]",arr);
    int i=0,ts=-1,tp=-1;
    while(arr[i]!='\0')
    {
        if(issalnum(arr[i]))
        {
            tp++;
            *(postfix+tp)=arr[i];
        }
        else if(pre(arr[i])!=0)
        {
            if(pre(arr[i])<=pre(*(stack+ts)))
            {
                while(pre(arr[i])<=pre(*(stack+ts)))
                {
                    tp++;
                    *(postfix+tp)=*(stack+ts);
                    ts--;
                }
            }
            else
            {
                ts++;
                *(stack+ts)=arr[i];
            }
        }
        else if(arr[i]=='(')
        {
            ts++;
            *(stack+ts)=arr[i];
        }
        else if(arr[i]==')')
        {
            while(*(stack+ts)!='(')
            {
                tp++;
                *(postfix+tp)=*(stack+ts);
                ts--;
            }
            ts--;
        }
        i++;
    }
    while(ts!=-1)
    {
        tp++;
        *(postfix+tp)=*(stack+ts);
        ts--;
    }
    *(postfix + tp +1)='\0';
    printf("The postfix expression is : %s",postfix);
    free(stack);
    free(postfix);
    return 0;
}