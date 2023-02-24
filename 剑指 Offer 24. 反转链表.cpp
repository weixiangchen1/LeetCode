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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr)
            return head;
        
        ListNode* Prev = nullptr, *Curr = head, *Next = head->next;
        while (Curr) {
            Curr->next = Prev;
            Prev = Curr;
            Curr = Next;
            if (Next)
                Next = Next->next;
        }

        return Prev;
    }
};
