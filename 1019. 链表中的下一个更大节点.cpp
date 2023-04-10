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
	vector<int> nextLargerNodes(ListNode* head) {
		vector<int> ans;
		while (head) {
			if (!head->next) ans.push_back(0);
			else {
				auto p = head;
				while (p) {
					if (p->val > head->val) {
						ans.push_back(p->val);
						break;
					}
					p = p->next;
				}
				if (!p) ans.push_back(0);
			}
			head = head->next;
		}

		return ans;
	}
};