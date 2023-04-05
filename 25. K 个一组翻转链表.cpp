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
	ListNode* reverseKGroup(ListNode* head, int k) {
		// ��������ͷ���
		ListNode* dummy = new ListNode(-1);
		dummy->next = head;

		ListNode* p = dummy;
		while (true) {
			// �Ƿ����k�����
			ListNode* q = p;
			for (int i = 0; i < k && q; ++i) q = q->next;
			if (q == nullptr) break;

			// ��תk��Ԫ��
			ListNode* node1 = p->next, *node2 = node1->next;
			for (int i = 0; i < k - 1; ++i) {
				ListNode* next = node2->next;
				node2->next = node1;
				node1 = node2;
				node2 = next;
			}

			ListNode* node3 = p->next;
			node3->next = node2;
			p->next = node1;
			p = node3;
		}

		return dummy->next;
	}
};



















