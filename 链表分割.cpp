/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        struct ListNode* lessHead, * lessTail, * greaterHead, * greaterTail;
        lessTail = lessHead = (struct ListNode*)malloc(sizeof(struct ListNode));
        greaterTail = greaterHead = (struct ListNode*)malloc(sizeof(struct ListNode));

        struct ListNode* cur = pHead;
        while (cur)
        {
            if (cur->val < x)
            {
                lessTail->next = cur;
                lessTail = cur;
            }
            else
            {
                greaterTail->next = cur;
                greaterTail = cur;
            }

            cur = cur->next;
        }

        lessTail->next = greaterHead->next;
        greaterTail->next = NULL;
        struct ListNode* newhead = lessHead->next;
  
        free(lessHead);
        free(greaterHead);

        return newhead;
    }
};
