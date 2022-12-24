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
    void flatten(TreeNode* root) {
        vector<TreeNode*> ans;
        FirstOrder(root, ans);
        ans.push_back(nullptr);

        for (int i=0; i<ans.size()-1; ++i) {
            ans[i]->right = ans[i+1];
            ans[i]->left = nullptr;
        }
    }

    void FirstOrder(TreeNode* root, vector<TreeNode*>& ans) {
        if (root == nullptr)
            return;
        
        ans.push_back(root);
        FirstOrder(root->left, ans);
        FirstOrder(root->right, ans);
    }
};
