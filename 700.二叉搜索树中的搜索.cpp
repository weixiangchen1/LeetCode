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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == nullptr)
            return nullptr;
        
        TreeNode* cur = root;
        while(cur) {
            if(cur->val > val) {
                cur = cur->left;
            }
            else if(cur->val < val) {
                cur = cur->right;
            }
            else {
                return cur;
            }
        }

        return nullptr;
    }
};
