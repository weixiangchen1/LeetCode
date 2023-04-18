class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
		stack<int> stk;
		vector<int> ans;
		unordered_map<int, int> hash;
		for (int i = nums2.size() - 1; i >= 0; --i) {
			while (!stk.empty() && stk.top() <= nums2[i]) {
				stk.pop();
			}
			if (!stk.empty())  {
				hash[nums2[i]] = stk.top();
			}
			else {
				hash[nums2[i]] = -1;
			}
			stk.push(nums2[i]);
		}
		for (int i = 0; i < nums1.size(); ++i) {
			ans.push_back(hash[nums1[i]]);
		}

		return ans;
	}
};