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
    vector<vector<int>> ans;

    void _pathSum(TreeNode* root, vector<int> sum, int target)
    {
        if (root == nullptr) return;
        sum.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            if (accumulate(sum.begin(), sum.end(), 0) == target) {
                ans.push_back(sum);
            }
        }
        _pathSum(root->left, sum, target);
        _pathSum(root->right, sum, target);
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return ans;
        vector<int> sum;
        _pathSum(root, sum, targetSum);

        return ans;
    }
};

