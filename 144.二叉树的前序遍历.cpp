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

void _preorderTraversal(struct TreeNode* root, int* a, int* pi)
{
    if(root == NULL)
        return;

    a[(*pi)++] = root->val;
    _preorderTraversal(root->left, a, pi);
    _preorderTraversal(root->right, a, pi);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize){
    int size = TreeSize(root);
    int* a = (int*)malloc(sizeof(int)*size);

    int i = 0;
    _preorderTraversal(root, a, &i);
    *returnSize = size;

    return a;
}
