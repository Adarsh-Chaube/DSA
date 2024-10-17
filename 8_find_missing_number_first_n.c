#include<stdio.h>
int main()
{
    int arr[100],i,sum=0,csum,n,e;
    printf("Enter the length of the array : ");
    scanf("%d",&n);
    printf("Enter the elements of the array : ");
    for(i=0;i<n;i++)
    {
        scanf ("%d",&arr[i]);
    }
    csum=(n+1)*(n+2)/2;
    for(i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    e=csum-sum;
    printf("The missing element from the array is : %d",e);
    return 0;
}