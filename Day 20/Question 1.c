#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

typedef struct {
    int key;
    int count;
} Hash;

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    Hash hash[MAX];
    int size = 0;

    int prefixSum = 0;
    int count = 0;

    // Add prefixSum = 0 initially
    hash[size++] = (Hash){0, 1};

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        int found = 0;

        // search if prefixSum already exists
        for (int j = 0; j < size; j++) {
            if (hash[j].key == prefixSum) {
                count += hash[j].count;
                hash[j].count++;
                found = 1;
                break;
            }
        }

        // if not found, insert
        if (!found) {
            hash[size++] = (Hash){prefixSum, 1};
        }
    }

    printf("%d\n", count);
    return 0;
}
