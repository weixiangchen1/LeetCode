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
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr)
            return head;

        ListNode* rightHead = new ListNode(-1);
        ListNode* leftHead = new ListNode(-1);
        ListNode* rightTail = rightHead, *leftTail = leftHead;
        while (head) {
            if (head->val < x) {
                leftTail->next = head;
                leftTail = leftTail->next;
            }
            else {
                rightTail->next = head;
                rightTail = rightTail->next;
            }
            head = head->next;
        }

        // 拼接两个链表
        leftTail->next = rightHead->next;
        rightTail->next = nullptr;

        return leftHead->next;
    }
};
