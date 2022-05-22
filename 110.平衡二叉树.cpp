/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int BinaryTreeDepth(struct TreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	int leftDepth = BinaryTreeDepth(root->left);
	int rightDepth = BinaryTreeDepth(root->right);

	return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}

bool isBalanced(struct TreeNode* root){
    if(root == NULL)
        return true;

    if(abs(BinaryTreeDepth(root->left) - BinaryTreeDepth(root->right)) > 1)
        return false;

    return isBalanced(root->left) && isBalanced(root->right);
}
