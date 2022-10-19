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
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next)
            return true;

        vector<int> val;
        while(head){
            val.push_back(head->val);
            head = head->next;
        }

        int left = 0, right = val.size()-1;
        while(left < right){
            if(val[left] != val[right])
                return false;
            
            left++;
            right--;
        }
        return true;
    }
};
