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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(-1);
        ListNode* cur = head;
        int tmp = 0;

        while(l1 || l2 || tmp){
            if(l1){
                tmp += l1->val;
                l1 = l1->next;
            }
            if(l2){
                tmp += l2->val;
                l2 = l2->next;
            }

            cur->next = new ListNode(tmp % 10);
            cur = cur->next;
            tmp /= 10;
        }

        return head->next;
    }
};
