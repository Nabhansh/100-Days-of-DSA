int maxSubArray(int* nums, int numsSize) {
    int maxSum = nums[0];
    int currSum = nums[0];

    for (int i = 1; i < numsSize; i++) {
        // either extend previous subarray or start new
        if (currSum < 0)
            currSum = nums[i];
        else
            currSum += nums[i];

        // update max
        if (currSum > maxSum)
            maxSum = currSum;
    }

    return maxSum;
}
