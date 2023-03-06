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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if (root != nullptr) q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> vec;
            while (size--) {
                TreeNode* tmp = q.front();
                q.pop();
                vec.push_back(tmp->val);

                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
            }
            ans.push_back(vec);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
