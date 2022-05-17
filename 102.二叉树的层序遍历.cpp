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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        int levelSize = 0;

        if(root)
        {
            q.push(root);
            levelSize = 1;
        }
        vector<vector<int>> vv;
        while(!q.empty())
        {
            vector<int> v;
            while(levelSize--)
            {
                TreeNode* front = q.front();
                v.push_back(front->val);
                q.pop();
                if(front->left)
                    q.push(front->left);
                if(front->right)
                    q.push(front->right);
            }

            levelSize = q.size();
            vv.push_back(v);
        }

        return vv;
    }
};
