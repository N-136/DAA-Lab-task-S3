#include<stdio.h>
#define max 64

void add(int A[max][max], int B[max][max], int C[max][max], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void subtract(int A[max][max], int B[max][max], int C[max][max], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

void strassen(int A[max][max], int B[max][max], int C[max][max], int n)
{
    int i, j, k;

    int A11[max][max], A12[max][max], A21[max][max], A22[max][max];
    int B11[max][max], B12[max][max], B21[max][max], B22[max][max];
    int M1[max][max], M2[max][max], M3[max][max], M4[max][max], M5[max][max], M6[max][max], M7[max][max];
    int X[max][max], Y[max][max];

    if (n == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    k = n / 2;
    for (i = 0; i < k; i++)
    {
        for (j = 0; j < k; j++)
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + k];
            A21[i][j] = A[i + k][j];
            A22[i][j] = A[i + k][j + k];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + k];
            B21[i][j] = B[i + k][j];
            B22[i][j] = B[i + k][j + k];
        }
    }

    add(A11, A22, X, k);
    add(B11, B22, Y, k);
    strassen(X, Y, M1, k);

    add(A21, A22, X, k);
    strassen(X, B11, M2, k);

    subtract(B12, B22, Y, k);
    strassen(A11, Y, M3, k);

    subtract(B21, B11, Y, k);
    strassen(A22, Y, M4, k);

    add(A11, A12, X, k);
    strassen(X, B22, M5, k);

    subtract(A21, A11, X, k);
    add(B11, B12, Y, k);
    strassen(X, Y, M6, k);

    subtract(A12, A22, X, k);
    add(B21, B22, Y, k);
    strassen(X, Y, M7, k);

    add(M1, M4, X, k);
    subtract(X, M5, Y, k);
    add(Y, M7, X, k);

    for (i = 0; i < k; i++)
        for (j = 0; j < k; j++)
            C[i][j] = X[i][j];

    add(M3, M5, X, k);

    for (i = 0; i < k; i++)
        for (j = 0; j < k; j++)
            C[i][j + k] = X[i][j];

    add(M2, M4, X, k);

    for (i = 0; i < k; i++)
        for (j = 0; j < k; j++)
            C[i + k][j] = X[i][j];

    subtract(M1, M2, X, k);
    add(X, M3, Y, k);
    add(Y, M6, X, k);

    for (i = 0; i < k; i++)
        for (j = 0; j < k; j++)
            C[i + k][j + k] = X[i][j];
}

int main()
{
    int A[max][max], B[max][max], C[max][max];
    int r1, c1, r2, c2;
    int size = 1;
    int i, j;

    printf("Enter order of first matrix: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter order of second matrix: ");
    scanf("%d %d", &r2, &c2);

    if (c1 != r2)
    {
        printf("\nMatrix multiplication is not possible");
        return 0;
    }

    printf("Enter first matrix:\n");
    for (i = 0; i < r1; i++)
        for (j = 0; j < c1; j++)
            scanf("%d", &A[i][j]);

    printf("Enter second matrix:\n");
    for (i = 0; i < r2; i++)
        for (j = 0; j < c2; j++)
            scanf("%d", &B[i][j]);

    while (size < r1 || size < c1 || size < r2 || size < c2)
        size = size * 2;

    strassen(A, B, C, size);

    printf("\nResultant matrix:\n");
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c2; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }
    return 0;
}
