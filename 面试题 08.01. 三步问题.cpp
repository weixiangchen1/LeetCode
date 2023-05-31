class Solution {
public:
	int waysToStep(int n) {
		// 0. ����߽�����
		if (n == 1 || n == 2) return n;
		if (n == 3) return 4;

		// 1. ����dp��
		vector<int>dp(n + 1);
		const int MOD = 1e9 + 7;

		// 2. ��ʼ��
		dp[1] = 1, dp[2] = 2, dp[3] = 4;

		// 3. ���
		for (int i = 4; i <= n; ++i)
			dp[i] = (((dp[i - 1] + dp[i - 2]) % MOD) + dp[i - 3]) % MOD;

		// 4. ����ֵ
		return dp[n];
	}
};