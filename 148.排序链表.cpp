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
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr) 
            return head;
        
        vector<int> nums;
        while (head) {
            nums.push_back(head->val);
            head = head->next;
        }
        sort(nums.begin(), nums.end());
        ListNode* newHead = new ListNode(-1);
        ListNode* prev = newHead;
        for (int i = 0; i < nums.size(); ++i) {
            ListNode* tail = new ListNode(nums[i]);
            prev->next = tail;
            prev = tail;
        }

        return newHead->next;
    }
};


