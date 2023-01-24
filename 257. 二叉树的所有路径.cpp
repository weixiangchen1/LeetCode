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

    void _binaryTreePaths(TreeNode* root, string str, vector<string>& ans) {
        if (root != nullptr) {
            str += to_string(root->val);
            if (root->left == nullptr && root->right == nullptr) {
                ans.push_back(str);
            }
            else {
                str += "->";
                _binaryTreePaths(root->left, str, ans);
                _binaryTreePaths(root->right, str, ans);
            }
        }          
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        _binaryTreePaths(root, "", ans);

        return ans;
    }
};
