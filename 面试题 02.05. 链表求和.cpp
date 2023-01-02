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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        int tmp = 0;
        while (l1 || l2 || tmp) {
            int sum = 0;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            sum += tmp;
            ListNode* newNode = new ListNode(sum % 10);
            cur->next = newNode;
            tmp = sum / 10;
            cur = cur->next;
        }

        return dummy->next;        
    }
};
