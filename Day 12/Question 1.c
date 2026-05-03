#include <stdio.h>

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);

    int A[m][n];

    // Read matrix
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    // Condition 1: must be square
    if (m != n)
    {
        printf("Not a Symmetric Matrix\n");
        return 0;
    }

    // Condition 2: check symmetry (only half needed)
    for (int i = 0; i < m; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (A[i][j] != A[j][i])
            {
                printf("Not a Symmetric Matrix\n");
                return 0;
            }
        }
    }

    printf("Symmetric Matrix\n");
    return 0;
}