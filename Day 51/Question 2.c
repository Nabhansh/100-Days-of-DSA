struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    while (root) {
        if (p->val < root->val && q->val < root->val) {
            root = root->left;   // both nodes are in left subtree
        } else if (p->val > root->val && q->val > root->val) {
            root = root->right;  // both nodes are in right subtree
        } else {
            return root;         // split point → LCA
        }
    }
    return NULL;
}
