/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while(cur) {
            if (cur->val == val) {
                if (prev == nullptr) {
                    head = cur->next;
                }
                else {
                    prev->next = cur->next;
                }
            }
            prev = cur;
            cur = cur->next;
        }
        return head;
    }
};
