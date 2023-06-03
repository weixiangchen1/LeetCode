class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_set<int> hash;
		vector<int> ans;
		for (auto& x : nums) {
			if (hash.count(target - x)) {
				ans.push_back(x);
				ans.push_back(target - x);
				break;
			}
			hash.insert(x);
		}
		return ans;
	}
};