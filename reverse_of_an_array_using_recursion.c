#include<stdio.h>
void revarr(int [],int,int,int);
int main()
{
    int arr[100],n,l,r,i;
    printf("Enter the length of the the array : ");
    scanf("%d",&n);
    printf("Enter the elements of the array : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    l=0;
    r=n-1;
    revarr(arr,n,l,r);
    printf("The reversed array is : ");
        for(int i=0;i<n;i++)
        {
            printf("%d\t",arr[i]);
        }
    return 0;
}
void revarr(int arr[],int n,int l,int r)
{
    int temp;
    if(l<r)
    {
        temp=arr[l];
        arr[l]=arr[r];
        arr[r]=temp;
        revarr(arr,n,l+1,r-1);
    }
}
    