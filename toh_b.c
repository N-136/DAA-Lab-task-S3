//without recursion
#include <stdio.h>
#include <math.h>

void move(int r1[], int *t1, int r2[], int *t2, char a, char b)
{
    int x;

    if (*t1 == -1)
    {
        x = r2[(*t2)--];
        r1[++(*t1)] = x;
        printf("Move disk %d from %c to %c\n", x, b, a);
    }
    else if (*t2 == -1)
    {
        x = r1[(*t1)--];
        r2[++(*t2)] = x;
        printf("Move disk %d from %c to %c\n", x, a, b);
    }
    else if (r1[*t1] < r2[*t2])
    {
        x = r1[(*t1)--];
        r2[++(*t2)] = x;
        printf("Move disk %d from %c to %c\n", x, a, b);
    }
    else
    {
        x = r2[(*t2)--];
        r1[++(*t1)] = x;
        printf("Move disk %d from %c to %c\n", x, b, a);
    }
}

int main()
{
    int n, i, moves;

    printf("Enter number of disks: ");
    scanf("%d", &n);

    int A[n], B[n], C[n];
    int topA = n - 1, topB = -1, topC = -1;

    for (i = 0; i < n; i++)
        A[i] = n - i;

    moves = (int)pow(2, n) - 1;

    for (i = 1; i <= moves; i++)
    {
        if (n % 2 == 1)
        {
            if (i % 3 == 1)
                move(A, &topA, C, &topC, 'A', 'C');
            else if (i % 3 == 2)
                move(A, &topA, B, &topB, 'A', 'B');
            else
                move(B, &topB, C, &topC, 'B', 'C');
        }
        else
        {
            if (i % 3 == 1)
                move(A, &topA, B, &topB, 'A', 'B');
            else if (i % 3 == 2)
                move(A, &topA, C, &topC, 'A', 'C');
            else
                move(B, &topB, C, &topC, 'B', 'C');
        }
    }

    return 0;
}
