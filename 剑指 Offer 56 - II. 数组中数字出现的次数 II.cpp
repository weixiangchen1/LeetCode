class Solution {
public:
	int singleNumber(vector<int>& nums) {
		unordered_map<int, int> hash;
		for (auto& x : nums) hash[x]++;
		for (auto& it : hash) {
			if (it.second == 1) {
				return it.first;
			}
		}
		return -1;
	}
};