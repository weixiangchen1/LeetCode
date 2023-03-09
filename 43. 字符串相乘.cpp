class Solution {
public:
	string multiply(string num1, string num2) {
		int n = num1.size(), m = num2.size();
		vector<int> v1, v2;
		for (int i = n - 1; i >= 0; --i) v1.push_back(num1[i] - '0');
		for (int i = m - 1; i >= 0; --i) v2.push_back(num2[i] - '0');

		vector<int> ans(n + m);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				ans[i + j] += v1[i] * v2[j];
			}
		}
		int tmp = 0;
		for (int i = 0; i < n + m; ++i) {
			tmp += ans[i];
            ans[i] = tmp % 10;
            tmp /= 10;
		}

		int k = n + m - 1;
		while (k > 0 && ans[k] == 0) k--;

		string res;
		for (int i = k; i >= 0; --i)
		{
			res += (ans[i] + '0');
		}

		return res;
	}
};
