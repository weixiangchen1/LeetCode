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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return bulid(nums, 0, nums.size()-1);
    }

    TreeNode* bulid(vector<int>&nums, int l, int r) {
        if(l > r) {
            return nullptr;
        }

        int mid = l + r >> 1;
        auto root = new TreeNode(nums[mid]);
        root->left = bulid(nums, l, mid-1);
        root->right = bulid(nums, mid+1, r);

        return root;
    }
};
