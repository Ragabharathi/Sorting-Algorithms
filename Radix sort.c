#include<stdio.h>

int getmax(int[],int);
void countsort(int[],int,int);

void radixsort(int a[],int n)
{
    int max=getmax(a,n);
    for(int pos=1;(max/pos)>0;pos*=10)
    {
        countsort(a,n,pos);
    }
}

int getmax(int a[],int n)
{
    int max=a[0];
    for(int i=0;i<n;i++)
    {
        if(a[i]>max)
        {
            max=a[i];
        }
    }
    return max;
}

void countsort(int a[],int n,int pos)
{
    int count[10]={0};
    int b[n];
    for(int i=0;i<n;i++)
    {
        count[(a[i]/pos)%10]++;
    }
    for(int i=1;i<10;i++)
    {
        count[i]=count[i]+count[i-1];
    }
    for(int i=n-1;i>=0;i--)
    {
        b[--count[(a[i]/pos)%10]]=a[i];
    }
    for(int i=0;i<n;i++)
    {
        a[i]=b[i];
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
    int n;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Elements before sorting:\n");
    print(a,n);
    radixsort(a,n);
    printf("Elements after sorting:\n");
    print(a,n);
    return 0;
}
