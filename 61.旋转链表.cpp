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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || k == 0)
            return head;

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* tail = head, *cur = head;
        int num = 1;
        while (tail->next) {
            tail = tail->next;
            num++;
        }
        num = num - k%num;
        if (num == 0)
            return head;
        
        for (int i=0; i<num-1; ++i) {
            cur = cur->next;
        }
        tail->next = head;
        dummy->next = cur->next;
        cur->next = nullptr;
        
        return dummy->next;
    }
};
