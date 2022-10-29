/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        ListNode* cur = head;
        while(cur)
        {
            nums.push_back(cur->val);
            cur = cur->next;
        }

        return _sortedListToBST(nums, 0, nums.size()-1);
    }

    TreeNode* _sortedListToBST(vector<int>& nums, int l, int r) {
        if(l > r) {
            return nullptr;
        }

        int mid = l + r >> 1;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = _sortedListToBST(nums, l, mid-1);
        root->right = _sortedListToBST(nums, mid+1, r);

        return root;
    }

};
