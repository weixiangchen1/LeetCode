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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (root == nullptr)
            return nullptr;

        // root->val < low  递归右子树是否大于low 
        if (root->val < low)
            return trimBST(root->right, low, high);
        // root->val > high 递归左子树是否大于high
        if (root->val > high)
            return trimBST(root->left, low, high);

        // low <= root->val <= high 正常结点，递归左右子树检查
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);

        return root;
    }
};
