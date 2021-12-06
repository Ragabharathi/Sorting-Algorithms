#include <stdio.h>

void maxheapify(int a[],int n,int i)
{
    int largest=i;
    int right=(2*i)+2;
    int left=(2*i)+1;
    while(left<n && a[left]>a[largest])
    {
        largest=left;
    }
    while(right<n && a[right]>a[largest])
    {
        largest=right;
    }
    if(largest!=i)
    {
        int temp=a[i];
        a[i]=a[largest];
        a[largest]=temp;
        maxheapify(a,n,largest);
    }
}

void heapsort(int a[],int n)
{
    for(int i=((n/2)-1);i>=0;i--)
    {
        maxheapify(a,n,i);
    }
    for(int i=n-1;i>=0;i--)
    {
        int temp=a[i];
        a[i]=a[0];
        a[0]=temp;
        maxheapify(a,i,0);
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
    heapsort(a,n);
    printf("After sorting\n");
    print(a,n);
    return 0;
}
