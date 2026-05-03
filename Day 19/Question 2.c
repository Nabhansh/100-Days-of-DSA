int maxSubarraySumCircular(int* nums, int numsSize) {
    int totalSum = 0;

    int currMax = nums[0], maxSum = nums[0];
    int currMin = nums[0], minSum = nums[0];

    for (int i = 0; i < numsSize; i++) {
        int x = nums[i];

        totalSum += x;

        // Kadane for max subarray
        if (i == 0)
            currMax = x;
        else
            currMax = (currMax > 0) ? currMax + x : x;

        if (currMax > maxSum)
            maxSum = currMax;

        // Kadane for min subarray
        if (i == 0)
            currMin = x;
        else
            currMin = (currMin < 0) ? currMin + x : x;

        if (currMin < minSum)
            minSum = currMin;
    }

    // If all numbers are negative
    if (maxSum < 0)
        return maxSum;

    // return best of both cases
    return (maxSum > (totalSum - minSum)) ? maxSum : (totalSum - minSum);
}
