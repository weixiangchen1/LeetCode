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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        int flag = 1;
        if (root) q.push(root);
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
            if (flag == -1) {
                reverse(vec.begin(), vec.end());
            }
            flag *= -1;
            ans.push_back(vec);
        }

        return ans;
    }
};
