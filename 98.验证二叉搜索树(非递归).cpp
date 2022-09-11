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
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> st;
        long long prevVal = LLONG_MIN;
        while(!st.empty() || root != nullptr)
        {
            while(root != nullptr)
            {
                st.push(root);
                root = root->left;
            }

            TreeNode* top = st.top();
            st.pop();

            if(top->val <= prevVal)
                return false;

            prevVal = top->val;
            root = top->right;
        }

        return true;
    }
};



