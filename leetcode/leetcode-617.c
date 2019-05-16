/*
 * 617. Merge Two Binary Trees
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2){
    if(t1 == NULL && t2 == NULL) {
        return NULL;
    }
    struct TreeNode * node = (struct TreeNode *) malloc(sizeof(struct TreeNode));
    if(t1 == NULL){
        node->val = t2->val;
        node->left = mergeTrees(NULL, t2->left);
        node-> right = mergeTrees(NULL, t2->right);
    } else if (t2 == NULL) {
        node->val = t1->val;
        node->left = mergeTrees(t1->left, NULL);
        node-> right = mergeTrees(t1->right, NULL);
    } else {
        node->val = t1->val + t2->val;
        node->left = mergeTrees(t1->left, t2->left);
        node-> right = mergeTrees(t1->right, t2->right);
    }
    return node;
}
