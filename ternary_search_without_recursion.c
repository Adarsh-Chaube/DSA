#include<stdio.h>
int terser(int , int [],int,int,int);
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
    i=terser(k,arr,n,l,r);
    if(i==-1){
        printf("The element is not present in the array!!!!");
        return 0;
    }
    printf("The index of the key is : %d",i);
    return 0;
}
int terser(int k,int arr[],int n,int l,int r)
{
    int i,m1,m2;
    m1=l+(r-l)/3;
    m2=r-(r-l)/3;
    while(m1<=m2 && m1>=l && m2<=r)
    {   
        if(k>arr[r] || k<arr[l])
            return -1;
        if(k==arr[m1])
            return m1;
        if(k==arr[m2])
            return m2;
        if(k<arr[m1])
            m1--;
        else if(k>arr[m2])
            m2++;
        else{
            m2--;
            m1++;
        }
    }
    return -1;
}