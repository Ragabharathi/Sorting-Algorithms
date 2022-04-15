#include <stdio.h>
 
void cycle_sort(int a[],int n)
{
    int temp, item, pos, i, j, k;
 
    for (i = 0;i <n; i++)
    {
        item = a[i];
        pos = i;
        do
        {
            k = 0;
            for (j = 0;j < n;j++)
            {
                if (pos != j && a[j] < item)
                {
                    k++;
                }
            }
            if (pos != k)
             {
                while (pos != k && item == a[k])
                {
                    k++;
                }
                temp = a[k];
                a[k] = item;
                item = temp;
                pos = k;
            }
        }while (pos != i);
    }
}

 
int main()
{
    int n;
    scanf("%d",&n);
    int a[n],i;
    for (i = 0;i <n; i++)
    {
        scanf("%d", &a[i]);
    }
    cycle_sort(a,n);
    printf("sorted elements are :\n");
    for (i = 0;i <n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}


