/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int *vals;
int getMaxInRangeIndex(int m, int n) {
    int max = vals[m];
    int index = m;
    for(int i = m, j = n; i <= j; i++, j--) {
        if(vals[i] <= vals[j] && vals[j] >= max) {
            max = vals[j];
            index = j;
        } else if(vals[i] >= vals[j] && vals[i] >= max) {
            max = vals[i];
            index = i;
        } else {
            //nothing
        }
    }
    return index;
}

struct TreeNode* construct(int m, int n, int size) {
    struct TreeNode * node = (struct TreeNode *) malloc(sizeof(struct TreeNode));
    if (m < 0 || n >= size || m > n) {
        return NULL;
    }
    int rootIndex = getMaxInRangeIndex(m, n);
    node->val = vals[rootIndex];
    node->left = construct(m, rootIndex - 1, size);
    node->right = construct(rootIndex + 1, n, size);
    return node;
}

struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize){
    vals = nums;
    return construct (0, numsSize - 1, numsSize);
}

