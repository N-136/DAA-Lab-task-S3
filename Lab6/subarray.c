#include <stdio.h>
#include <limits.h>

int maxCrossing(int a[], int low, int mid, int high, int *start, int *end)
{
    int leftSum = INT_MIN, rightSum = INT_MIN;
    int sum = 0, i, left, right;

    for(i = mid; i >= low; i--)
    {
        sum += a[i];
        if(sum > leftSum)
        {
            leftSum = sum;
            left = i;
        }
    }
    sum = 0;
    for(i = mid + 1; i <= high; i++)
    {
        sum += a[i];
        if(sum > rightSum)
        {
            rightSum = sum;
            right = i;
        }
    }

    *start = left;
    *end = right;

    return leftSum + rightSum;
}

int maxSubarray(int a[], int low, int high, int *start, int *end)
{
    int mid;
    int leftSum, rightSum, crossSum;
    int leftStart, leftEnd, rightStart, rightEnd;
    int crossStart, crossEnd;

    if(low == high)
    {
        *start = *end = low;
        return a[low];
    }

    mid = (low + high) / 2;

    leftSum = maxSubarray(a, low, mid, &leftStart, &leftEnd);

    rightSum = maxSubarray(a, mid + 1, high, &rightStart, &rightEnd);

    crossSum = maxCrossing(a, low, mid, high, &crossStart, &crossEnd);

    if(leftSum >= rightSum && leftSum >= crossSum)
    {
        *start = leftStart;
        *end = leftEnd;
        return leftSum;
    }
    else if(rightSum >= leftSum && rightSum >= crossSum)
    {
        *start = rightStart;
        *end = rightEnd;
        return rightSum;
    }
    else
    {
        *start = crossStart;
        *end = crossEnd;
        return crossSum;
    }
}

int main()
{
    int n,i;
    int start,end,sum;

    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    int a[n];
    printf("Enter elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    sum = maxSubarray(a, 0, n-1, &start, &end);

    printf("\nMaximum subarray: ");
    for(i = start; i <= end; i++)
        printf("%d ", a[i]);

    printf("\nMaximum subarray sum = %d", sum);

    return 0;
}
