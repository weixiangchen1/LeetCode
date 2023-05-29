class Solution {
public:
	int numDecodings(string s) {
		// 状态表示: dp[i]表示从开始到i位置的解码方法的总数
		// 状态转移方程:
		// 1. s[i]单独解码
		//    a. 解码成功 0<=s[i]<=9 dp[i]+=dp[i-1] 
		//    b. 解码失败 dp[i] += 0
		// 2. s[i]和s[i-1]一起解码
		//    a. 解码成功 10<=s[i]*10+s[i-1]<=26 dp[i]+=dp[i-2]
		//    b. 解码失败 dp[i] += 0
		// 返回值: dp[n-1]

		// 创建dp表
		int n = s.size();
		vector<int> dp(n, 0);
		// 初始化dp表
		dp[0] = (s[0] != '0') ? 1 : 0;
		if (n == 1) return dp[0];
		if (s[1] >= '1' && s[1] <= '9') dp[1] += dp[0];
		int t = (s[0] - '0') * 10 + s[1] - '0';
		if (10 <= t && t <= 26) dp[1] += 1;

		// 填写dp表
		for (int i = 2; i < n; ++i)
		{
			if (s[i] >= '1' && s[i] <= '9') dp[i] += dp[i - 1];  // dp[i]单独解码
			int t = (s[i - 1] - '0') * 10 + s[i] - '0';
			if (10 <= t && t <= 26) dp[i] += dp[i - 2]; // dp[i]和dp[i-1]一起解码
		}
		// 返回值
		return dp[n - 1];
	}
};