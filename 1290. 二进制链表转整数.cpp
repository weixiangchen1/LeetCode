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
    ListNode* resever(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* prev = NULL, *cur = head, *Next = head->next;
        while (cur) {
            cur->next = prev;
            prev = cur;
            cur = Next;
            if (Next) 
                Next = Next->next;
        }
        return prev;
    }

    int getDecimalValue(ListNode* head) {
        int ans = 0, tmp = 0;
        ListNode* newNode = resever(head);
        while (newNode) {
            ans += newNode->val * pow(2, tmp);
            tmp++;
            newNode = newNode->next;
        }
        return ans;
    }
};
