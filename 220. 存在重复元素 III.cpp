class Solution {
public:
	typedef long long LL;
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		multiset<LL> s;
		s.insert(1e18), s.insert(-1e18);
		for (int i = 0, j = 0; i < nums.size(); ++i) {
			if (i - j > k) s.erase(s.find(nums[j++]));
			auto it = s.lower_bound(nums[i]);
			if (*it - nums[i] <= t) return true;
			--it;
			if (nums[i] - *it <= t) return true;
			s.insert(nums[i]);
		}

		return false;
	}
};