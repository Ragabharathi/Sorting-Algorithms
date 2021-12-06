#include <stdio.h>
#include <stdio.h>

void cyclesort(int a[],int n)
{
    int i=0;
    while(i<n)
    {
        int correct=a[i]-1;
        if(a[i]!=a[correct])
        {
            int temp=a[i];
            a[i]=a[correct];
            a[correct]=temp;
        }
        else
        {
            i++;
        }
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
    cyclesort(a,n);
    printf("After sorting\n");
    print(a,n);
    return 0;
}
