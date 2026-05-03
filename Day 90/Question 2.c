#include <stdio.h>

int isPossible(int arr[], int n, int k, int maxTime) {
    int painters = 1;
    int currSum = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxTime)
            return 0;

        if (currSum + arr[i] <= maxTime) {
            currSum += arr[i];
        } else {
            painters++;
            currSum = arr[i];

            if (painters > k)
                return 0;
        }
    }
    return 1;
}

// Main function
int minTime(int arr[], int n, int k) {
    int max = 0, sum = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > max) max = arr[i];
        sum += arr[i];
    }

    int low = max, high = sum, ans = sum;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (isPossible(arr, n, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

// -------- MAIN --------
int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("%d\n", minTime(arr, n, k));

    return 0;
}
