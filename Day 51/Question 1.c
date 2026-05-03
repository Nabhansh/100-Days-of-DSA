#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int val;
    struct Node *left, *right;
};

// Create new node
struct Node* createNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Insert into BST
struct Node* insert(struct Node* root, int val) {
    if (root == NULL)
        return createNode(val);

    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// Find LCA
struct Node* LCA(struct Node* root, int p, int q) {
    while (root != NULL) {
        if (p < root->val && q < root->val)
            root = root->left;
        else if (p > root->val && q > root->val)
            root = root->right;
        else
            return root; // split point
    }
    return NULL;
}

// -------- MAIN --------
int main() {
    int N;
    scanf("%d", &N);

    struct Node* root = NULL;

    // Input BST
    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        root = insert(root, x);
    }

    int p, q;
    scanf("%d %d", &p, &q);

    struct Node* ans = LCA(root, p, q);

    if (ans)
        printf("%d\n", ans->val);

    return 0;
}
