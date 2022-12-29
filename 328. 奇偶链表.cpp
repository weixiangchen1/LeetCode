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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr)
            return head;
        
        ListNode* rightHead = new ListNode(-1);
        ListNode* leftHead = new ListNode(-1);
        ListNode* rightTail = rightHead, *leftTail = leftHead;
        int len = 1;
        while (head) {
            if (len % 2 == 0) {
                leftTail->next = head;
                leftTail = leftTail->next;
            }
            else
            {
                rightTail->next = head;
                rightTail = rightTail->next;
            }
            len++;
            head = head->next;
        }
        rightTail->next = leftHead->next;
        leftTail->next = nullptr;
        return rightHead->next;
    }
};
