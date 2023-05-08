class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		vector<int> ans(digits);
		ans[ans.size() - 1]++;
		if (ans[ans.size() - 1] == 10) {
			ans[ans.size() - 2]++;
			ans.push_back(0);
		}
		return ans;
	}
};