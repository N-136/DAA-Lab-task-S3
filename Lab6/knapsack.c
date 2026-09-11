#include <stdio.h>
#include <stdlib.h>

struct Item
{
    int weight;
    int profit;
    float ratio;
};

int compare(const void *a, const void *b)
{
    struct Item *x = (struct Item *)a;
    struct Item *y = (struct Item *)b;

    if (x->ratio < y->ratio)
        return 1;
    else if (x->ratio > y->ratio)
        	return -1;
    else
        return 0;
}

int main()
{
    struct Item item[100];
    int n, capacity, i;
    float totalProfit = 0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weight and profit of each item:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &item[i].weight, &item[i].profit);
        item[i].ratio = (float)item[i].profit / item[i].weight;
    }

    printf("Enter capacity of knapsack: ");
    scanf("%d", &capacity);

    qsort(item, n, sizeof(struct Item), compare);

    for (i = 0; i < n; i++)
    {
        if (capacity == 0)
            break;
        if (item[i].weight <= capacity)
        {
            capacity -= item[i].weight;
            totalProfit += item[i].profit;
        }
        else
        {
            totalProfit += item[i].ratio * capacity;
            capacity = 0;
        }
    }
    printf("\nMaximum profit = %.2f", totalProfit);

    return 0;
}
