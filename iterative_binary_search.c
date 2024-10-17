#include<stdio.h>
int binser(int[],int,int,int);
int main()
{
    int arr[100],l,r,k,n,i;
    printf("Enter the length of the array : ");
    scanf("%d",&n);
    printf("Enter the elements of the array : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the key to be searched : ");
    scanf("%d",&k);
    l=0;
    r=n-1;
    i=binser(arr,k,l,r);
    if (i==-1)
    {printf("The element is not present in the array !!");
        return 0;}  
    printf("The element is present at index : %d",i);
    return 0;
}
int binser(int arr[], int k,int l,int r)
{
    int  mid;
    while(l<=r)
    {
        mid=l+(r-l)/2;
        if(arr[mid]==k)
            return mid;
        if(arr[mid]>k)
            r=mid-1;
        else if (arr[mid]<k)
            l=mid+1;
    }
    return -1;
}