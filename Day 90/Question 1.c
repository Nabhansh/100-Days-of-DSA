#include <stdio.h>

// Check if we can split into <= k subarrays with max sum <= mid
int canSplit(int* nums, int n, int k, int mid) {
    int count = 1;
    long long currSum = 0;

    for (int i = 0; i < n; i++) {
        if (currSum + nums[i] <= mid) {
            currSum += nums[i];
        } else {
            count++;
            currSum = nums[i];
            if (count > k)
                return 0;
        }
    }
    return 1;
}

int splitArray(int* nums, int numsSize, int k) {
    int maxVal = 0;
    long long sum = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > maxVal) maxVal = nums[i];
        sum += nums[i];
    }

    long long low = maxVal, high = sum, ans = sum;

    while (low <= high) {
        long long mid = (low + high) / 2;

        if (canSplit(nums, numsSize, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return (int)ans;
}
