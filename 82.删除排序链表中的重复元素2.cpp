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
            // �ҵ������Ľ���е����һ�����
            while (cur->next && cur->val == cur->next->val) {
                cur = cur->next;
            }
            // û�������ظ����
            if (prev->next == cur) {
                prev = prev->next;
            }
            // �����ظ����
            else {
                prev->next = cur->next;
            }
            cur = cur->next;
        }

        return dummy->next;
    }
};
