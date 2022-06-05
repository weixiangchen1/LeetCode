/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    if(head == NULL)
        return NULL;

    struct ListNode* Prev = NULL;
    struct ListNode* Cur = head;
    struct ListNode* Next = head->next;

    while(Cur)
    {
        Cur->next = Prev;

        Prev = Cur;
        Cur = Next;
        if(Next)
        {
            Next = Next->next;
        }        
    }

    return Prev;
}
