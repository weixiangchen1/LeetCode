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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        vector<int> ans;

        while(cur || !st.empty())
        {
            while(cur)
            {
                st.push(cur);
                cur = cur->left;
            }
            TreeNode* top = st.top();
            st.pop();
            ans.push_back(top->val);

            cur = top->right;
        }

        return ans;
    }
};
