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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr)
            return head;

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* Prevleft = dummy;
        for (int i = 0; i < left - 1; ++i) {
            Prevleft = Prevleft->next;
        }
        // 翻转指定位置链表结点
        ListNode* node1 = Prevleft->next;
        ListNode* node2 = node1->next;
        for (int i = 0; i < right - left; ++i) {
            ListNode* next = node2->next;
            node2->next = node1;
            node1 = node2;
            node2 = next;
        }
        // 拼接首尾结点
        Prevleft->next->next = node2;
        Prevleft->next = node1;

        return dummy->next;
    }
};
