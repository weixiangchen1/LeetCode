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
    bool FindPath(TreeNode* root, TreeNode* x, stack<TreeNode*>& Path)
    {
        if(root == nullptr)
            return false;
        
        Path.push(root);
        if(root == x)
            return true;

        if(FindPath(root->left, x, Path) || FindPath(root->right, x, Path))
            return true;

        Path.pop();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> qPath;
        stack<TreeNode*> pPath;
        FindPath(root, p, pPath);
        FindPath(root, q, qPath);
         
        while(qPath.size() != pPath.size())
        {
            if(qPath.size() > pPath.size())
                qPath.pop();
            else
                pPath.pop();
        }

        while(qPath.top() != pPath.top())
        {
            qPath.pop();
            pPath.pop();
        }

        return qPath.top();
    }
};
