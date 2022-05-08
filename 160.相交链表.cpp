/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode * curA = headA;
    struct ListNode * curB = headB;
    int countA = 0, countB = 0;
    while(curA)
    {
        ++countA;
        curA = curA->next;
    }
    while(curB)
    {
        ++countB;
        curB = curB->next;
    }
    if(curA != curB)
        return NULL;
    int gap = abs(countA - countB);
    struct ListNode* longlist = headA;
    struct ListNode* shortlist = headB;
    if(countA < countB)
    {
        longlist = headB;
        shortlist = headA;
    }
    while(gap--)
    {
        longlist = longlist->next;
    }
    while(longlist != shortlist)
    {
        longlist = longlist->next;
        shortlist = shortlist->next;
    }

    return longlist;
}
