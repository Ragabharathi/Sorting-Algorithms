#include<stdio.h>

int getmax(int[],int);

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

void countsort(int a[],int n)
{
    int k=getmax(a,n);
    int count[k+1];
    for(int i=0;i<k+1;i++)
    count[i]=0;
    int b[n];
    for(int i=0;i<n;i++)
    {
        count[a[i]]++;
    }
    for(int i=1;i<=k;i++)
    {
        count[i]=count[i]+count[i-1];
    }
    for(int i=n-1;i>=0;i--)
    {
        b[--count[a[i]]]=a[i];
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
    countsort(a,n);
    printf("Elements after sorting:\n");
    print(a,n);
    return 0;
}
