#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // sort the array
    qsort(arr, n, sizeof(int), cmp);

    int left = 0, right = n - 1;

    int minSum = arr[left] + arr[right];
    int x = arr[left], y = arr[right];

    while (left < right) {
        int sum = arr[left] + arr[right];

        // update closest pair
        if (abs(sum) < abs(minSum)) {
            minSum = sum;
            x = arr[left];
            y = arr[right];
        }

        // move pointers
        if (sum < 0) {
            left++;   // need larger sum
        } else {
            right--;  // need smaller sum
        }
    }

    printf("%d %d\n", x, y);
    return 0;
}
