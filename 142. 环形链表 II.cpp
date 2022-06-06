/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
        {
            struct ListNode* meetNode = slow;
            while(head != slow)
            {
                slow = slow->next;
                head = head->next;
            }

            return slow;
        }
    }

    return NULL;
}
