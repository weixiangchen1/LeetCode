class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		bool vis[9];

		// 判断行元素
		for (int i = 0; i < 9; ++i) {
			memset(vis, 0, sizeof(vis));
			for (int j = 0; j < 9; ++j) {
				if (board[i][j] != '.') {
					int t = board[i][j] - '1';
					if (vis[t]) return false;
					vis[t] = true;
				}
			}
		}

		// 判断列元素
		for (int i = 0; i < 9; ++i) {
			memset(vis, 0, sizeof(vis));
			for (int j = 0; j < 9; ++j) {
				if (board[j][i] != '.') {
					int t = board[j][i] - '1';
					if (vis[t]) return false;
					vis[t] = true;
				}
			}
		}

		// 判断3*3元素
		for (int i = 0; i < 9; i += 3) {
			for (int j = 0; j < 9; j += 3) {
				memset(vis, 0, sizeof(vis));
				for (int x = 0; x < 3; x++) {
					for (int y = 0; y < 3; y++) {
						if (board[i + x][j + y] != '.') {
							int t = board[i + x][j + y] - '1';
							if (vis[t]) return false;
							vis[t] = true;
						}
					}
				}
			}
		}

		return true;
	}
};