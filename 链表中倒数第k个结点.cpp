/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 *
 * C������������ȫ�ֱ��������static����ֹ�ظ�����
 */

/**
 * 
 * @param pListHead ListNode�� 
 * @param k int���� 
 * @return ListNode��
 */
struct ListNode* FindKthToTail(struct ListNode* pListHead, int k ) {
    // write code here
    if(pListHead == NULL || k <= 0)
        return NULL;
    struct ListNode* fast = pListHead;
    struct ListNode* slow = pListHead;
    
    while(k--)
    {
        if(fast == NULL)
            return NULL;
        else
            fast = fast->next;
        
    }
    while(fast)
    {
        fast = fast->next;
        slow = slow->next;
    }
    
    return slow;
}
