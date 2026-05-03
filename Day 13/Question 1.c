#include <stdio.h>

int main()
{
    int r, c;
    scanf("%d %d", &r, &c);

    int A[r][c];

    // input
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    int top = 0, bottom = r - 1;
    int left = 0, right = c - 1;

    while (top <= bottom && left <= right)
    {

        // 1. left → right (top row)
        for (int j = left; j <= right; j++)
        {
            printf("%d ", A[top][j]);
        }
        top++;

        // 2. top → bottom (right column)
        for (int i = top; i <= bottom; i++)
        {
            printf("%d ", A[i][right]);
        }
        right--;

        // 3. right → left (bottom row)
        if (top <= bottom)
        {
            for (int j = right; j >= left; j--)
            {
                printf("%d ", A[bottom][j]);
            }
            bottom--;
        }

        // 4. bottom → top (left column)
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                printf("%d ", A[i][left]);
            }
            left++;
        }
    }

    return 0;
}