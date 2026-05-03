int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    if (!root) return NULL;

    int maxLevels = 2001;
    int** result = (int**)malloc(maxLevels * sizeof(int*));
    *returnColumnSizes = (int*)malloc(maxLevels * sizeof(int));

    struct TreeNode** queue = (struct TreeNode**)malloc(maxLevels * sizeof(struct TreeNode*));
    int front = 0, back = 0;
    queue[back++] = root;

    while (front < back) {
        int levelSize = back - front;
        result[*returnSize] = (int*)malloc(levelSize * sizeof(int));
        (*returnColumnSizes)[*returnSize] = levelSize;

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = queue[front++];
            result[*returnSize][i] = node->val;

            if (node->left)  queue[back++] = node->left;
            if (node->right) queue[back++] = node->right;
        }

        (*returnSize)++;
    }

    free(queue);
    return result;
}
