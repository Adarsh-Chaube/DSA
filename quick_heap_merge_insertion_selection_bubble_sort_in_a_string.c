#include<stdio.h>
#include<string.h>
void remove_dup(char str[])
{
    int i=0,j,l;
    while(str[i]!='\0')
    {
        j=i+1;
        while(str[j]!='\0')
        {
            if(str[i]==str[j])
            {
                l=j;
                while(str[l]!='\0')
                {
                    str[l]=str[l+1];
                    l++;
                }
            }
            j++;
        }
        i++;
    }
}
void bubble(char str[])
{
    int l=strlen(str);
    for(int i=0;i<l-1;i++)
    {
        for(int j=i;j<(l-i-1);j++)
        {
            if(str[j]>str[j+1])
            {
                char temp=str[j];
                str[j]=str[j+1];
                str[j+1]=temp;
            }
        }
    }
}
void merge(char str[],int l,int r,int m)
{
    int i,j,n,n1;
    n=m-l+1;
    n1=r-m;
    char ls[n],rs[n1];
    for(i=0;i<n;i++)
    {
        ls[i]=str[l+i];
    }
    for(i=0;i<n1;i++)
    {
        rs[i]=str[m+1+i];
    }
    i=j=0;
    int k=l;
    while(i<n && j<n1)
    {
        if(ls[i]>=rs[j])
        {
            str[k]=rs[j];
            j++;
        }
        else{
            str[k]=ls[i];
            i++;
        }
        k++;
    }
    while(j<n1)
    {
        str[k]=rs[j];
        j++;
        k++;
    }
    while(i<n)
    {
        str[k]=ls[i];
        i++;
        k++;
    }
}
void merge_sort(char str[],int l,int r)
{
    int m=l+(r-l)/2;
    if(l<r)
    {
        merge_sort(str,l,m);
        merge_sort(str,m+1,r);
        merge(str,l,r,m);
    }
}
void insertion_sort(char arr[])
{
    int l=strlen(arr);
    for(int i=1;i<l;i++)
    {
        int k=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>k)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=k;
    }
}
void selection_sort(char arr[])
{
    int l=strlen(arr);
    for(int i=0;i<(l-1);i++)
    {
        int mi=i;
        for(int j=i+1;j<l;j++)
        {
            if(arr[j]<arr[mi])
                mi=j;
        }
        char temp=arr[i];
        arr[i]=arr[mi];
        arr[mi]=temp;
    }
}
/*int partition(char arr[],int l,int r)   
//Lomuto's partition
{
    char pivot=arr[r];
    int i=l-1,j;
    for(j=l;j<r;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            char temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    char temp=arr[i+1];
    arr[i+1]=pivot;
    arr[r]=temp;
    return (i+1);
}*/
int partition(char arr[],int l,int r)
//Hoare's partition : the pivot element might not be in its true position after partition but finally all elements will come to their place
{
    int i=l-1,j=r+1;
    char pivot=arr[l];
    while(1)
    {
        do
        {
            i++;
        }while(arr[i]<pivot);
        do{
            j--;
        }while(arr[j]>pivot);
        if(i>=j)
            return j;
        char temp=arr[j];
        arr[j]=arr[i];
        arr[i]=temp;
    }
}
void quickSort(char arr[],int l,int r)
{
    if(l<r)
    {
        int pi=partition(arr,l,r);
        quickSort(arr,l,pi);//for Lomuto : quickSort(arr,l,pi-1) as the partition element is at its position
        quickSort(arr,pi+1,r);
    }
}
void max_heapify(char arr[],int n,int i)
{
    int l=2*i+1,r=2*i+2,largest=i;
    if(l<n && arr[l]>arr[largest])
        largest=l;
    if(r<n && arr[r]>arr[largest])
        largest=r;
    if(largest!=i)
    {
        char temp=arr[i];
        arr[i]=arr[largest];
        arr[largest]=temp;
        max_heapify(arr,n,largest);
    }
}
void heap_sort(char arr[])
{
    int n=strlen(arr);
    for(int i=n/2;i>=0;i--)
    {
        max_heapify(arr,n,i);
    }
    for(int i=n-1;i>0;i--)
    {
        char temp=arr[0];
        arr[0]=arr[i];
        arr[i]=temp;
        max_heapify(arr,i,0);
    }
}
int main()
{
    char name[20],fname[20],mname[20],str[100];
    int c;
    printf("Enter your name : ");
    scanf(" %[^\n]",&name);
    printf("Enter your fathers' name : ");
    scanf(" %[^\n]",&fname);
    printf("Enter your mothers' name : ");
    scanf(" %[^\n]",&mname);
    strcpy(str,name);
    strcat(str,fname);
    strcat(str,mname);
    remove_dup(str);
    printf("The final string is : %s",str);
    printf("\nEnter 1-for bubble sort\n2-Insertion sort\n3-Quick sort\n4-Heap sort\n5-Merge sort\n6-Selection sort\nEnter your choice : ");
    scanf("%d",&c);
    switch(c)
    {
        case 1:
            bubble(str);
            printf("The string after sorting is : %s",str);
            break;
        case 2:
            insertion_sort(str);
            printf("The string after sorting is : %s",str);
            break;
        case 3:
            quickSort(str,0,strlen(str)-1);
            printf("The string after sorting is : %s",str);
            break;
        case 4:
            heap_sort(str);
            printf("The string after sorting is : %s",str);
            break;
        case 5:
            merge_sort(str,0,strlen(str)-1);
            printf("The string after sorting is : %s",str);
            break;
        case 6:
            selection_sort(str);
            printf("The string after sorting is : %s",str);
            break;
    }
    return 0;
}