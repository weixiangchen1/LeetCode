/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool Find(TreeNode* root, TreeNode* x)
    {
        if(root == nullptr)
            return false;
        
        if(root == x)
            return true;
        else
            return Find(root->left, x) || Find(root->right, x);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr)
            return nullptr;

        if(root == p || root == q)
            return root;

        bool pInLeft, pInRight, qInLeft, qInRight;
        pInLeft = Find(root->left, p);
        pInRight = !pInLeft;
        qInLeft = Find(root->left, q);
        qInRight = !qInLeft;

        if((pInLeft && qInRight) || (pInRight && qInLeft))
        {
            return root;
        }
        else if(pInLeft && qInLeft)
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        else if(pInRight && qInRight)
        {
            return lowestCommonAncestor(root->right, p, q);
        }
        else
        {
            return nullptr;
        }
    }
};
