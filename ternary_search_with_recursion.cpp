#include<stdio.h>
int terser(int , int [],int,int);
int main()
{
    int arr[100],l,r,n,k,i;
    printf("Enter the length of the array : ");
    scanf("%d",&n);
    l=0;
    r=n-1;
    printf("Enter the elements of the array : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the key to be searched : ");
    scanf("%d",&k);
    i=terser(k,arr,l,r);
    if(i==-1){
        printf("The element is not present in the array!!!!");
        return 0;
    }
    printf("The index of the key is : %d",i);
    return 0;
}
int terser(int k,int arr[],int l,int r)
{
    int i,m1,m2;
    m1=l+(r-l)/3;
    m2=r-(r-l)/3;
    if(l<=r)
    {
        if(arr[m1]==k)
            return m1;
        if(arr[m2]==k)
            return m2;
        if(arr[m1]>k)
            terser(k,arr,l,m1-1);
        else if(arr[m2]<k)
            terser(k,arr,m2+1,r);
        else
            terser(k,arr,m1+1,m2-1);
    }
    return -1;
}