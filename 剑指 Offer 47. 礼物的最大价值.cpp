class Solution {
public:
	int maxValue(vector<vector<int>>& grid) {
		int n = grid.size(), m = grid[0].size();
		vector<vector<int>> dp(n, vector<int>(m, 0));
		for (int i = 0; i < grid.size(); ++i) {
			for (int j = 0; j < grid[i].size(); ++j) {
				if (i == 0 && j == 0) dp[i][j] = grid[i][j];
				else {
					if (i != 0) dp[i][j] = max(dp[i][j], dp[i - 1][j] + grid[i][j]);
					if (j != 0) dp[i][j] = max(dp[i][j], dp[i][j - 1] + grid[i][j]);
				}
			}
		}

		return dp[n - 1][m - 1];
	}
};