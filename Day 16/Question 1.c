#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int freq[1001] = {0}; // assuming values ≤ 1000

    // count frequencies
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }

    // print results
    for (int i = 0; i < n; i++)
    {
        if (freq[arr[i]] != 0)
        {
            printf("%d:%d ", arr[i], freq[arr[i]]);
            freq[arr[i]] = 0; // avoid duplicate printing
        }
    }

    return 0;
}