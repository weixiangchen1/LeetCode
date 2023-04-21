class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		unordered_set<int> s;
		for (auto& x : nums) s.insert(x);

		int ans = 0;
		for (auto& x : nums) {
			if (s.count(x) && !s.count(x - 1)) {
				int y = x;
				s.erase(x);
				while (s.count(y + 1)) {
					++y;
					s.erase(y);
				}
				ans = max(ans, y - x + 1);
			}
		}

		return ans;
	}
};