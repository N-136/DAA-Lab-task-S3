//method 2
#include<stdio.h>
int partition(int a[],int low,int high)
{
    int pivot=a[high];
    int i=low;
    int j,temp;

    for(j=low;j<high;j++)
    {
        if(a[j]<pivot)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            i++;
        }
    }
    temp = a[i];
    a[i] = a[high];
    a[high] = temp;
    return i;
}

int quickselect(int a[], int low, int high, int k)
{
    int p;
    if(low == high)
        return a[low];
    p = partition(a, low, high);
    if(p == k)
        return a[p];
    if(k < p)
        return quickselect(a, low, p - 1, k);
    return quickselect(a, p + 1, high, k);
}

int main()
{
    int n, k, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter k value: ");
    scanf("%d", &k);

    printf("The Kth smallest element is %d", quickselect(a, 0, n - 1, k - 1));
    return 0;
}
