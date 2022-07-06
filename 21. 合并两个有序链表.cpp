/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if(l1 == NULL)
        return l2;
    if(l2 == NULL)
        return l1;
        
    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;
    while(l1 && l2)
    {
        if(l1->val < l2->val)
        {
            if(head == NULL)
            {
                head = tail = l1;
            }
            else
            {
                tail->next = l1;
                tail = l1;
            }
            l1 = l1->next;
        }
        else
        {
            if(head == NULL)
            {
                head = tail = l2;
            }
            else
            {
                tail->next = l2;
                tail = l2;
            }
            l2 = l2->next;
        }
    }
      
    if(l1)
    {
        tail->next = l1;
    }
    
    if(l2)
    {
        tail->next = l2;
    }

    return head;
}
