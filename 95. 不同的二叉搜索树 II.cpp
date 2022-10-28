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
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) {
            return vector<TreeNode*>();
        }
        else {
            return _generateTrees(1, n);
        }
    }

    vector<TreeNode*> _generateTrees(int left, int right) {
        vector<TreeNode*> res;
        if(left > right) {
            res.push_back(nullptr);
            return res;
        }        

        for(int i = left; i <= right; ++i) {
            vector<TreeNode*> LeftTree = _generateTrees(left, i-1);
            vector<TreeNode*> RightTree = _generateTrees(i+1, right);

            for(auto left : LeftTree) {
                for(auto right : RightTree) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;

                    res.push_back(root);
                }
            }
        }

        return res;
    }
};

