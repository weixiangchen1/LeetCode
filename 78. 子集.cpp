class Solution {
public:
	vector<vector<int>> ans;

	void dfs(vector<int>& nums, int t, vector<int>& tmp) {
		if (tmp.size() == nums.size()) return;

		if (t <= nums.size() - 1) {
			tmp.push_back(nums[t]);
			ans.push_back(tmp);
			dfs(nums, t + 1, tmp);
			tmp.pop_back();
			dfs(nums, t + 1, tmp);
		}
	}

	vector<vector<int>> subsets(vector<int>& nums) {
		vector<int> tmp;
		ans.push_back({});
		for (int i = 0; i < nums.size(); ++i) {
			dfs(nums, i, tmp);
		}
		sort(ans.begin(), ans.end());
		ans.erase(unique(ans.begin(), ans.end()), ans.end());

		return ans;
	}
};