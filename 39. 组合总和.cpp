class Solution {
public:
	vector<vector<int>> ans;

	void dfs(vector<int>& candidates, vector<int>& tmp, int target)
	{
		if (accumulate(tmp.begin(), tmp.end(), 0) == target) {
			ans.push_back(tmp);
			return;
		}

		for (int i = 0; i < candidates.size(); ++i) {
			if (accumulate(tmp.begin(), tmp.end(), 0) > target)
				return;
			tmp.push_back(candidates[i]);
			dfs(candidates, tmp, target);
			tmp.pop_back();
		}
	}

	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<int> tmp;
		dfs(candidates, tmp, target);

		for (auto& x : ans) {
			sort(x.begin(), x.end());
		}

		sort(ans.begin(), ans.end());
		ans.erase(unique(ans.begin(), ans.end()), ans.end());

		return ans;
	}
};