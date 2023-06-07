/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	int Depth(TreeNode* root) {
		if (!root) return 0;

		return max(Depth(root->right), Depth(root->left)) + 1;
	}

	bool isBalanced(TreeNode* root) {
		if (!root) return true;
		int leftDepth = Depth(root->left);
		int rightDepth = Depth(root->right);

		return abs(leftDepth - rightDepth) < 2 && isBalanced(root->left) && isBalanced(root->right);
	}
};