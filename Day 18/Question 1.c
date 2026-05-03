#include <stdio.h>

void reverse(int arr[], int left, int right)
{
    while (left < right)
    {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int k;
    scanf("%d", &k);

    // handle k > n
    k = k % n;

    // 1) reverse whole array
    reverse(arr, 0, n - 1);

    // 2) reverse first k elements
    reverse(arr, 0, k - 1);

    // 3) reverse remaining elements
    reverse(arr, k, n - 1);

    // print result
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}