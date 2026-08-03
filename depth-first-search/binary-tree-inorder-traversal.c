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
 int c=0;
 int test(struct TreeNode* root, int* returnSize)
 {
    if(!root)
    {
        return 0;
    }
    c++;
    test(root->left, returnSize);
    test(root->right, returnSize);
    return c;
 }
 void fun(struct TreeNode* root, int* ret)
 {
    if(!root)
    {
        return;
    }
    fun(root->left, ret);
    ret[c++] = root->val;
    fun(root->right, ret);
    return;
 }
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* ret = NULL;
    c = test(root, returnSize);
    ret = (int*)calloc(c,sizeof(int));
    c = 0;
    fun(root, ret);
    *returnSize = c;
    c =0;
    return ret;
}