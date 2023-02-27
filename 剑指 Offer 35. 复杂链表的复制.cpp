/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        // 两结点之间复制新结点
        for (Node* p = head; p; p = p->next->next)
        {
            Node* q = new Node(p->val);
            q->next = p->next;
            p->next = q;
        }

        // 连接random指针
        for (Node* p = head; p; p = p->next->next)
        {
            if (p->random)
                p->next->random = p->random->next;
        }

        Node* dummy = new Node(-1), *cur = dummy;
        for (Node* p = head; p; p = p->next)
        {
            cur->next = p->next;
            p->next = cur->next->next;
            cur = cur->next;
        }

        return dummy->next;
    }
};
