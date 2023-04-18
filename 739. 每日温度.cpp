class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& temperatures) {
		stack<pair<int, int>> stk;
		vector<int> ans;
		for (int i = temperatures.size() - 1; i >= 0; --i) {
			while (!stk.empty() && stk.top().first <= temperatures[i])
				stk.pop();
			if (!stk.empty()) ans.push_back(stk.top().second - i);
			else ans.push_back(0);
			stk.push({ temperatures[i], i });
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
};