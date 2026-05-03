#include <stdlib.h>

int *spiralOrder(int **matrix, int matrixSize, int *matrixColSize, int *returnSize)
{
    int m = matrixSize;
    int n = matrixColSize[0];

    int *result = (int *)malloc(m * n * sizeof(int));
    int k = 0;

    int top = 0, bottom = m - 1;
    int left = 0, right = n - 1;

    while (top <= bottom && left <= right)
    {

        // 1. left → right (top row)
        for (int j = left; j <= right; j++)
        {
            result[k++] = matrix[top][j];
        }
        top++;

        // 2. top → bottom (right column)
        for (int i = top; i <= bottom; i++)
        {
            result[k++] = matrix[i][right];
        }
        right--;

        // 3. right → left (bottom row)
        if (top <= bottom)
        {
            for (int j = right; j >= left; j--)
            {
                result[k++] = matrix[bottom][j];
            }
            bottom--;
        }

        // 4. bottom → top (left column)
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                result[k++] = matrix[i][left];
            }
            left++;
        }
    }

    *returnSize = k;
    return result;
}