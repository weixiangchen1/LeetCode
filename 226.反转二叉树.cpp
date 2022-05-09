/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void _invertTree(struct TreeNode* root)
{
    if(root == NULL)
        return;
        
    struct TreeNode* tmp = root->left;
    root->left = root->right;
    root->right = tmp;

    _invertTree(root->right);
    _invertTree(root->left);
}

struct TreeNode* invertTree(struct TreeNode* root){
    if(root == NULL)
        return NULL;
    
    _invertTree(root);

    return root;
}
