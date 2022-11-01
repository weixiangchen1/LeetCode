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
    void InOrder(TreeNode* root, vector<int>& ans) {
        if(root == nullptr) {
            return;
        }

        InOrder(root->left, ans);
        if(root->left == nullptr && root->right == nullptr) {
            ans.push_back(root->val);
        }
        InOrder(root->right, ans);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1;
        vector<int> v2;
        InOrder(root1, v1);
        InOrder(root2, v2);

        if(v1.size() != v2.size()) {
            return false;
        }

        cout << endl;
        for(int i=0; i<v1.size(); ++i) {
            if(v1[i] != v2[i]) {
                return false;
            }
        }

        return true;
    }
};




