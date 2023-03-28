/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode() : val(0), left(nullptr), right(nullptr) {}
*     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
*     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
* };
*/
class Solution {
public:
	int cnt = 0;
	void _pathSum(TreeNode* root, int targetSum, long long val)
	{
		if (!root) return;

		long long cur_val = val + root->val;

		if (cur_val == targetSum) cnt++;

		_pathSum(root->left, targetSum, cur_val);
		_pathSum(root->right, targetSum, cur_val);
	}

	void GetTree(TreeNode* root, int targetSum)
	{
		if (!root) return;

		_pathSum(root, targetSum, 0);

		GetTree(root->left, targetSum);
		GetTree(root->right, targetSum);
	}

	int pathSum(TreeNode* root, int targetSum) {
		if (!root) return 0;

		GetTree(root, targetSum);

		return cnt;
	}
};