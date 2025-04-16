//------------------------
//Leetcode 144
//------------------------
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(200 * sizeof(int));
    *returnSize = 0;
    if (root == NULL) return result;

    struct TreeNode** stack = (struct TreeNode**)malloc(200 * sizeof(struct TreeNode*));
    int top = -1;
    stack[++top] = root;

    while (top >= 0) {
        struct TreeNode* node = stack[top--];
        result[(*returnSize)++] = node->val;

        if (node->right) stack[++top] = node->right;
        if (node->left) stack[++top] = node->left;
    }

    free(stack);
    return result;
}


//------------------------
//Leetcode 94
//------------------------
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(200 * sizeof(int));
    struct TreeNode** stack = (struct TreeNode**)malloc(200 * sizeof(struct TreeNode*));
    int top = -1;
    *returnSize = 0;

    struct TreeNode* current = root;

    while (current != NULL || top >= 0) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }

        current = stack[top--];
        result[(*returnSize)++] = current->val;

        current = current->right;
    }

    free(stack);
    return result;
}
