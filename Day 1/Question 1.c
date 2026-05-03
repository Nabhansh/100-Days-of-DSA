#include <stdio.h>

int main()
{
    int n;

    // Input size
    scanf("%d", &n);

    int arr[100]; // assume max size

    // Input array
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int pos, x;

    // Input position (1-based) and element
    scanf("%d", &pos);
    scanf("%d", &x);

    // Shift elements to the right
    for (int i = n; i >= pos; i--)
    {
        arr[i] = arr[i - 1];
    }

    // Insert element
    arr[pos - 1] = x;

    // Print updated array
    for (int i = 0; i <= n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}