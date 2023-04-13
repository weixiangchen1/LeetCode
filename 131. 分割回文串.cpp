class Solution {
public:
	vector<vector<string>> ans;
	vector<string> path;
	int n;

	bool isPalindrome(string s) {
		string str = s;
		reverse(s.begin(), s.end());
		return s == str;
	}

	void dfs(string&s, int i) {
		if (i == n) {
			ans.push_back(path);
			return;
		}
		for (int j = i; j < n; ++j) {
			string sub_str = s.substr(i, j - i + 1);
			if (isPalindrome(sub_str)) {
				path.push_back(sub_str);
				dfs(s, j + 1);
				path.pop_back();
			}
		}
	}

	vector<vector<string>> partition(string s) {
		n = s.size();
		dfs(s, 0);
		return ans;
	}
};