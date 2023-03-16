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
	vector<int> levelOrder(TreeNode* root) {
		if (root == nullptr) return vector<int>();
		queue<TreeNode*> q;
		vector<int> ans;
		q.push(root);
		while (!q.empty()) {
			int size = q.size();
			while (size--) {
				TreeNode* tmp = q.front();
				q.pop();
				ans.push_back(tmp->val);

				if (tmp->left) q.push(tmp->left);
				if (tmp->right) q.push(tmp->right);
			}
		}

		return ans;
	}
};