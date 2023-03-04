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
    vector<int> ans;

    void _sumNumbers(TreeNode* root, int sum) {
        if (root == nullptr) 
            return;
        
        sum = sum*10 + root->val;
        if (root->left == nullptr && root->right == nullptr) {
            ans.push_back(sum);
        }
        _sumNumbers(root->left, sum);
        _sumNumbers(root->right, sum);
    }

    int sumNumbers(TreeNode* root) {
        if (root == nullptr) return 0;
        _sumNumbers(root, 0);

        return accumulate(ans.begin(), ans.end(), 0);
    }
};
