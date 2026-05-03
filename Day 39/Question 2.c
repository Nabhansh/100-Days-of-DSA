#include <stdlib.h>

#define OFFSET 10000

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    
    int freq[20001] = {0};

    // Count frequency
    for (int i = 0; i < numsSize; i++) {
        freq[nums[i] + OFFSET]++;
    }

    // Count unique elements
    int unique = 0;
    for (int i = 0; i < 20001; i++) {
        if (freq[i] > 0) unique++;
    }

    // Store (value, frequency)
    int (*arr)[2] = malloc(unique * sizeof *arr);
    int idx = 0;

    for (int i = 0; i < 20001; i++) {
        if (freq[i] > 0) {
            arr[idx][0] = i - OFFSET;
            arr[idx][1] = freq[i];
            idx++;
        }
    }

    // Sort by frequency descending
    int cmp(const void* a, const void* b) {
        return ((int*)b)[1] - ((int*)a)[1];
    }

    qsort(arr, unique, sizeof(arr[0]), cmp);

    // Take top k
    int* result = malloc(k * sizeof(int));
    for (int i = 0; i < k; i++) {
        result[i] = arr[i][0];
    }

    *returnSize = k;
    free(arr);
    return result;
}
