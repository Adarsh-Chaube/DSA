#include<stdio.h>
int main()
{
    int arr[100],i,n,e=0;
    printf("Enter the length of the array : ");
    scanf ("%d",&n);
    printf("Enter the elements of the array :");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        e=e^arr[i];
    }
    printf("The element appearing odd number of times is : %d",e);
    return 0;
}