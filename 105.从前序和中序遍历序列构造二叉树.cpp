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
    TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder,
    int& prei, int inbegin, int inend){
        if(inbegin > inend)
        {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[prei]);
        int rooti = inbegin;
        while(rooti <= inend)
        {
            if(inorder[rooti] == preorder[prei])
            {
                break;
            }
            else
            {
                ++rooti;
            }
        }
        ++prei;
        root->left = _buildTree(preorder, inorder, prei, inbegin, rooti-1);
        root->right = _buildTree(preorder, inorder, prei, rooti+1, inend);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int prei = 0;
        return _buildTree(preorder, inorder, prei, 0, inorder.size()-1);
    }
};
