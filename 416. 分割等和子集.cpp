class Solution {
public:
	bool canPartition(vector<int>& nums) {
		// 01背包问题，从数中选出等于总和一半的方案
		int sum = 0;
		for (auto x : nums) sum += x;
		if (sum % 2 != 0) return false;
		sum /= 2;
		vector<bool> dp(sum + 1);
		dp[0] = 1;
		for (auto x : nums)
		for (int j = sum; j >= x; j--)
			dp[j] = dp[j] | dp[j - x];

		return dp[sum];
	}
};