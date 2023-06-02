/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (!headA || !headB) return nullptr;
		int longLength = 0, shortLength = 0;
		ListNode* La = headA, *Lb = headB;
		while (La) {
			longLength++;
			La = La->next;
		}
		while (Lb) {
			shortLength++;
			Lb = Lb->next;
		}

		if (longLength < shortLength){
			swap(longLength, shortLength);
			swap(headB, headA);
		}
		int cnt = longLength - shortLength;
		cout << cnt << endl;
		while (cnt-- && headA) headA = headA->next;

		while (headA && headB) {
			if (headA == headB) return headA;
			headA = headA->next;
			headB = headB->next;
		}

		return nullptr;
	}
};