#include <stdio.h>
#include <stdbool.h>
int n;
void printsol(int b[n][n], int n)
{
    int i, j;

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
            printf("%d ", b[i][j]);

        printf("\n");
    }
}

bool place(int b[n][n], int row, int col, int n)
{
    int i, j;

    for(i = 0; i < col; i++)
        if(b[row][i])
            return false;

    for(i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if(b[i][j])
            return false;

    for(i = row, j = col; i < n && j >= 0; i++, j--)
        if(b[i][j])
            return false;

    return true;
}

bool solvenq(int b[n][n], int col, int n)
{
    int i;

    if(col >= n)
        return true;

    for(i = 0; i < n; i++)
    {
        if(place(b, i, col, n))
        {
            b[i][col] = 1;

            if(solvenq(b, col + 1, n))
                return true;

            // Backtracking
            b[i][col] = 0;
        }
    }

    return false;
}

int main()
{
    int i, j;

    printf("Enter n value: ");
    scanf("%d", &n);

    if(n < 1)
    {
        printf("Invalid input");
        return 0;
    }

    int b[n][n];

    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            b[i][j] = 0;

    if(solvenq(b, 0, n) == false)
    {
        printf("\nSolution does not exist");
        return 0;
    }

    printf("\nSolution:\n");
    printsol(b, n);

    return 0;
}

