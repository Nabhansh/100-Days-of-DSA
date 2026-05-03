#include <stdio.h>

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);

    int A[m][n];

    // input matrix
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    int sum = 0;

    // diagonal sum
    for (int i = 0; i < m && i < n; i++)
    {
        sum += A[i][i];
    }

    printf("%d\n", sum);

    return 0;
}