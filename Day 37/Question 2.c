#include <stdlib.h>

typedef struct {
    int* heap;
    int size;
    int k;
} KthLargest;

// swap
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// heapify up
void heapifyUp(KthLargest* obj, int i) {
    while (i > 0 && obj->heap[(i - 1) / 2] > obj->heap[i]) {
        swap(&obj->heap[i], &obj->heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// heapify down
void heapifyDown(KthLargest* obj, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < obj->size && obj->heap[left] < obj->heap[smallest])
        smallest = left;

    if (right < obj->size && obj->heap[right] < obj->heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&obj->heap[i], &obj->heap[smallest]);
        heapifyDown(obj, smallest);
    }
}

// insert into heap
void insert(KthLargest* obj, int val) {
    obj->heap[obj->size] = val;
    heapifyUp(obj, obj->size);
    obj->size++;
}

// replace root (when size == k)
void replaceRoot(KthLargest* obj, int val) {
    obj->heap[0] = val;
    heapifyDown(obj, 0);
}

// constructor
KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    KthLargest* obj = (KthLargest*)malloc(sizeof(KthLargest));
    obj->heap = (int*)malloc(sizeof(int) * (k + 1));
    obj->size = 0;
    obj->k = k;

    for (int i = 0; i < numsSize; i++) {
        if (obj->size < k) {
            insert(obj, nums[i]);
        } else if (nums[i] > obj->heap[0]) {
            replaceRoot(obj, nums[i]);
        }
    }

    return obj;
}

// add element
int kthLargestAdd(KthLargest* obj, int val) {
    if (obj->size < obj->k) {
        insert(obj, val);
    } else if (val > obj->heap[0]) {
        replaceRoot(obj, val);
    }

    return obj->heap[0]; // kth largest
}

void kthLargestFree(KthLargest* obj) {
    free(obj->heap);
    free(obj);
}
