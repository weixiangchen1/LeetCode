/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */

struct Node* copyRandomList(struct Node* head) {
    if(head == NULL)
        return NULL;
	struct Node* cur = head;
    //1.将copy链接到cur后
    while(cur)
    {
        struct Node* copy = (struct Node*)malloc(sizeof(struct Node));
        copy->val = cur->val;
        copy->next = cur->next;
        cur->next = copy;
        
        cur = copy->next;
    }
    //2.处理copy的random指针
    cur = head;
    while(cur)
    {    
        struct Node* copy = cur->next;
        if(cur->random == NULL)
            copy->random = NULL;
        else
            copy->random = cur->random->next;

        cur = copy->next;
    }
    //3.断开copy结点，恢复原链表
    cur = head;
    struct Node* copyHead = NULL, *copyTail = NULL;
    while(cur)
    {
        struct Node* copy = cur->next;
        struct Node* next = copy->next;

        if(copyTail == NULL)
        {
            copyTail = copyHead = copy;
        }
        else
        {
            copyTail->next = copy;
            copyTail = copy;
        }
        cur->next = next;
        cur = next;
    }

    return copyHead;

}






