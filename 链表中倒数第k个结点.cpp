/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 *
 * C语言声明定义全局变量请加上static，防止重复定义
 */

/**
 * 
 * @param pListHead ListNode类 
 * @param k int整型 
 * @return ListNode类
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
