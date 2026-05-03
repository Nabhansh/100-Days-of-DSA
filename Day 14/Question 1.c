#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int A[n][n];

    // input matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    // check identity
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            if (i == j)
            {
                if (A[i][j] != 1)
                {
                    printf("Not an Identity Matrix\n");
                    return 0;
                }
            }
            else
            {
                if (A[i][j] != 0)
                {
                    printf("Not an Identity Matrix\n");
                    return 0;
                }
            }
        }
    }

    printf("Identity Matrix\n");
    return 0;
}