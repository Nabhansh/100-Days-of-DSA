#include <stdlib.h>

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    
    int* result = (int*)malloc((numsSize - k + 1) * sizeof(int));
    int* deque = (int*)malloc(numsSize * sizeof(int));

    int front = 0, back = -1;
    int idx = 0;

    for (int i = 0; i < numsSize; i++) {

        // Remove out-of-window elements
        if (front <= back && deque[front] <= i - k) {
            front++;
        }

        // Maintain decreasing order
        while (front <= back && nums[deque[back]] < nums[i]) {
            back--;
        }

        // Add current index
        deque[++back] = i;

        // Store result when window is full
        if (i >= k - 1) {
            result[idx++] = nums[deque[front]];
        }
    }

    *returnSize = idx;
    free(deque);
    return result;
}
