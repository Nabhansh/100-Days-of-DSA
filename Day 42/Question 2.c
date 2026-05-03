#include <stdlib.h>

/* ----------- STRUCT DEFINITIONS ----------- */

// Max Heap
typedef struct {
    int *arr;
    int size;
} MaxHeap;

// Min Heap
typedef struct {
    int *arr;
    int size;
} MinHeap;

// MedianFinder
typedef struct {
    MaxHeap left;   // max heap (smaller half)
    MinHeap right;  // min heap (larger half)
} MedianFinder;


/* ----------- MAX HEAP FUNCTIONS ----------- */

void maxHeapifyUp(MaxHeap* h, int i) {
    while (i > 0 && h->arr[(i-1)/2] < h->arr[i]) {
        int temp = h->arr[i];
        h->arr[i] = h->arr[(i-1)/2];
        h->arr[(i-1)/2] = temp;
        i = (i-1)/2;
    }
}

void maxHeapifyDown(MaxHeap* h, int i) {
    int largest = i;
    int l = 2*i + 1, r = 2*i + 2;

    if (l < h->size && h->arr[l] > h->arr[largest]) largest = l;
    if (r < h->size && h->arr[r] > h->arr[largest]) largest = r;

    if (largest != i) {
        int temp = h->arr[i];
        h->arr[i] = h->arr[largest];
        h->arr[largest] = temp;
        maxHeapifyDown(h, largest);
    }
}

void maxInsert(MaxHeap* h, int val) {
    h->arr[h->size++] = val;
    maxHeapifyUp(h, h->size - 1);
}

int maxExtract(MaxHeap* h) {
    int root = h->arr[0];
    h->arr[0] = h->arr[--h->size];
    maxHeapifyDown(h, 0);
    return root;
}

int maxTop(MaxHeap* h) {
    return h->arr[0];
}


/* ----------- MIN HEAP FUNCTIONS ----------- */

void minHeapifyUp(MinHeap* h, int i) {
    while (i > 0 && h->arr[(i-1)/2] > h->arr[i]) {
        int temp = h->arr[i];
        h->arr[i] = h->arr[(i-1)/2];
        h->arr[(i-1)/2] = temp;
        i = (i-1)/2;
    }
}

void minHeapifyDown(MinHeap* h, int i) {
    int smallest = i;
    int l = 2*i + 1, r = 2*i + 2;

    if (l < h->size && h->arr[l] < h->arr[smallest]) smallest = l;
    if (r < h->size && h->arr[r] < h->arr[smallest]) smallest = r;

    if (smallest != i) {
        int temp = h->arr[i];
        h->arr[i] = h->arr[smallest];
        h->arr[smallest] = temp;
        minHeapifyDown(h, smallest);
    }
}

void minInsert(MinHeap* h, int val) {
    h->arr[h->size++] = val;
    minHeapifyUp(h, h->size - 1);
}

int minExtract(MinHeap* h) {
    int root = h->arr[0];
    h->arr[0] = h->arr[--h->size];
    minHeapifyDown(h, 0);
    return root;
}

int minTop(MinHeap* h) {
    return h->arr[0];
}


/* ----------- REQUIRED FUNCTIONS ----------- */

// Create object
MedianFinder* medianFinderCreate() {
    MedianFinder* obj = (MedianFinder*)malloc(sizeof(MedianFinder));

    obj->left.arr = (int*)malloc(50000 * sizeof(int));
    obj->right.arr = (int*)malloc(50000 * sizeof(int));

    obj->left.size = 0;
    obj->right.size = 0;

    return obj;
}

// Add number
void medianFinderAddNum(MedianFinder* obj, int num) {
    if (obj->left.size == 0 || num <= maxTop(&obj->left)) {
        maxInsert(&obj->left, num);
    } else {
        minInsert(&obj->right, num);
    }

    // Balance heaps
    if (obj->left.size > obj->right.size + 1) {
        minInsert(&obj->right, maxExtract(&obj->left));
    } else if (obj->right.size > obj->left.size) {
        maxInsert(&obj->left, minExtract(&obj->right));
    }
}

// Find median
double medianFinderFindMedian(MedianFinder* obj) {
    if (obj->left.size == obj->right.size) {
        return (maxTop(&obj->left) + minTop(&obj->right)) / 2.0;
    }
    return maxTop(&obj->left);
}

// Free memory
void medianFinderFree(MedianFinder* obj) {
    free(obj->left.arr);
    free(obj->right.arr);
    free(obj);
}
