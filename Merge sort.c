#include <stdio.h>

void merge(int[],int,int,int);


void mergesort(int a[],int lb,int ub)
{
    if(lb<ub)
    {
        int mid=(lb+ub)/2;
        mergesort(a,lb,mid);
        mergesort(a,mid+1,ub);
        merge(a,lb,mid,ub);
    }
}
void merge(int a[],int lb,int mid,int ub)
{
    int b[10]; 
    int i=lb;
    int j=mid+1;
    int k=lb;
    while(i<=mid && j<=ub)
    {
        if(a[i]<=a[j])
        {
            b[k]=a[i++];
        }
        else
        {
            b[k]=a[j++];
        }
        k++;
    }
    if(i>mid)
    {
        while(j<=ub)
        {
            b[k++]=a[j++];
        }
    }
    else
    {
        while(i<=mid)
        {
            b[k++]=a[i++];
        }
    }
    for(k=lb;k<=ub;k++)
    {
        a[k]=b[k];
    }
}
void print(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
int main()
{
    int a[100],n;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Before sorting\n");
    print(a,n);
    int lb=0;
    int ub=n-1;
    mergesort(a,lb,ub);
    printf("After sorting\n");
    print(a,n);
    return 0;
}
