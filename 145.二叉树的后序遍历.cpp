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

int TreeSize(struct TreeNode* root)
{
    return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}

void _postorderTraversal(struct TreeNode* root, int* a, int* pi)
{
    if(root == NULL)
        return;

    _postorderTraversal(root->left, a, pi);
    _postorderTraversal(root->right, a, pi);
    a[(*pi)++] = root->val;

}

int* postorderTraversal(struct TreeNode* root, int* returnSize){
    int size = TreeSize(root);
    int* a = (int*)malloc(sizeof(int)*size);

    int i = 0;
    _postorderTraversal(root, a, &i);
    *returnSize = size;

    return a;
}
