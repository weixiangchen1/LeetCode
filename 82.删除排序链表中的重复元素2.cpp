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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr)
            return nullptr;

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prev = dummy, *cur = head;
        while (cur) {
            // 找到连续的结点中的最后一个结点
            while (cur->next && cur->val == cur->next->val) {
                cur = cur->next;
            }
            // 没有遇到重复结点
            if (prev->next == cur) {
                prev = prev->next;
            }
            // 遇到重复结点
            else {
                prev->next = cur->next;
            }
            cur = cur->next;
        }

        return dummy->next;
    }
};
