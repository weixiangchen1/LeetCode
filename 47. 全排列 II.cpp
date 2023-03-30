
class Solution {
public:
	bool vis[10] = { false };
	vector<vector<int>> ans;

	void dfs(vector<int>& nums, vector<int>& tmp)
	{
		if (tmp.size() == nums.size()) {
			ans.push_back(tmp);
			return;
		}

		for (int i = 0; i < nums.size(); ++i) {
			if (!vis[i]) {
				tmp.push_back(nums[i]);
				vis[i] = true;
				dfs(nums, tmp);
				tmp.pop_back();
				vis[i] = false;
			}
		}
	}

	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<int> tmp;
		dfs(nums, tmp);

		sort(ans.begin(), ans.end());
		ans.erase(unique(ans.begin(), ans.end()), ans.end());

		return ans;
	}
};