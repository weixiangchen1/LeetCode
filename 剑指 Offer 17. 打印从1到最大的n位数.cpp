class Solution {
public:
	vector<int> printNumbers(int n) {
		int num = pow(10, n) - 1;
		vector<int> ans;
		for (int i = 1; i <= num; ++i) ans.push_back(i);

		return ans;
	}
};