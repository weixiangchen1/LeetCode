class NumMatrix {
public:
	NumMatrix(vector<vector<int>>& matrix) {
		sum.resize(matrix.size() + 1);
		for (auto& v : sum) v.resize(matrix[0].size() + 1);
		for (int i = 0; i < matrix.size(); ++i) {
			for (int j = 0; j < matrix[0].size(); ++j) {
				sum[i + 1][j + 1] = sum[i][j + 1] + sum[i + 1][j] - sum[i][j] + matrix[i][j];
			}
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		row1 += 1, col1 += 1, row2 += 1, col2 += 1;
		return sum[row2][col2] - sum[row1 - 1][col2] - sum[row2][col1 - 1] + sum[row1 - 1][col1 - 1];
	}
private:
	vector<vector<int>> sum;
};

/**
* Your NumMatrix object will be instantiated and called as such:
* NumMatrix* obj = new NumMatrix(matrix);
* int param_1 = obj->sumRegion(row1,col1,row2,col2);
*/