#include <stdio.h>

#define MAX 1000

int heap[MAX];
int size = 0;

// swap helper
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// heapify up (insert)
void heapifyUp(int i) {
    while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// heapify down (delete)
void heapifyDown(int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;

    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(smallest);
    }
}

// insert
void insert(int x) {
    heap[size] = x;
    heapifyUp(size);
    size++;
}

// delete (remove min)
int deleteMin() {
    if (size == 0) return -1;

    int root = heap[0];
    heap[0] = heap[size - 1];
    size--;

    heapifyDown(0);
    return root;
}

// peek
int peek() {
    if (size == 0) return -1;
    return heap[0];
}

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        char op[10];
        scanf("%s", op);

        if (op[0] == 'i') {  // insert
            int x;
            scanf("%d", &x);
            insert(x);
        }
        else if (op[0] == 'd') {  // delete
            printf("%d\n", deleteMin());
        }
        else if (op[0] == 'p') {  // peek
            printf("%d\n", peek());
        }
    }

    return 0;
}
