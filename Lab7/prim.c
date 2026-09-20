#include <stdio.h>
#define INF 9999

int main()
{
    int n, m, i, j, k;
    int u, v, w;
    int cost[10][10];
    int visited[10] = {0};
    int min, x, y;
    int total = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &m);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cost[i][j] = INF;
        }
    }

    printf("Enter edges (u v weight):\n");
    for (i = 0; i < m; i++)
    {
        scanf("%d %d %d", &u, &v, &w);
        cost[u][v] = w;
        cost[v][u] = w;
    }

    visited[0] = 1;

    printf("\nEdges in Minimum Spanning Tree:\n");
    for (k = 0; k < n - 1; k++)
    {
        min = INF;

        for (i = 0; i < n; i++)
        {
            if (visited[i])
            {
                for (j = 0; j < n; j++)
                {
                    if (!visited[j] && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }
        printf("%d - %d : %d\n", x, y, min);

        total += min;
        visited[y] = 1;
    }
    printf("Minimum Cost = %d\n", total);
    return 0;
}
