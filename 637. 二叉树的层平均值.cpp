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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> q;
        if (root) q.push(root);
        while (!q.empty()) {
            int size = q.size(), length = size;
            double avg = 0.0;
            while (length--) {
                TreeNode* tmp = q.front();
                q.pop();
                avg += tmp->val;

                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
            }
            ans.push_back(avg/size);
        }

        return ans;
    }
};
