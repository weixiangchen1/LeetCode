class Solution {
public:
	int numDecodings(string s) {
		// ״̬��ʾ: dp[i]��ʾ�ӿ�ʼ��iλ�õĽ��뷽��������
		// ״̬ת�Ʒ���:
		// 1. s[i]��������
		//    a. ����ɹ� 0<=s[i]<=9 dp[i]+=dp[i-1] 
		//    b. ����ʧ�� dp[i] += 0
		// 2. s[i]��s[i-1]һ�����
		//    a. ����ɹ� 10<=s[i]*10+s[i-1]<=26 dp[i]+=dp[i-2]
		//    b. ����ʧ�� dp[i] += 0
		// ����ֵ: dp[n-1]

		// ����dp��
		int n = s.size();
		vector<int> dp(n, 0);
		// ��ʼ��dp��
		dp[0] = (s[0] != '0') ? 1 : 0;
		if (n == 1) return dp[0];
		if (s[1] >= '1' && s[1] <= '9') dp[1] += dp[0];
		int t = (s[0] - '0') * 10 + s[1] - '0';
		if (10 <= t && t <= 26) dp[1] += 1;

		// ��дdp��
		for (int i = 2; i < n; ++i)
		{
			if (s[i] >= '1' && s[i] <= '9') dp[i] += dp[i - 1];  // dp[i]��������
			int t = (s[i - 1] - '0') * 10 + s[i] - '0';
			if (10 <= t && t <= 26) dp[i] += dp[i - 2]; // dp[i]��dp[i-1]һ�����
		}
		// ����ֵ
		return dp[n - 1];
	}
};