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
    TreeNode* _buildTree(vector<int>& inorder, vector<int>& postorder, 
    int& posti, int inbegin, int inend) {
        if(inbegin > inend)
        {
            return nullptr;
        }
        TreeNode* root = new TreeNode(postorder[posti]);
        int rooti = inend;
        while(inbegin <= rooti)
        {
            if(inorder[rooti] == postorder[posti])
            {
                break;
            }
            else
            {
                rooti--;
            }
        }
        posti--;
        root->right = _buildTree(inorder, postorder, posti, rooti+1, inend);
        root->left = _buildTree(inorder, postorder, posti, inbegin, rooti-1);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int posti = postorder.size()-1;
        return _buildTree(inorder, postorder, posti, 0, inorder.size()-1);
    }
};
