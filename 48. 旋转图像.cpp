class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int n = matrix.size();
		// �ضԽ��߷�ת
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < i; ++j) {
				swap(matrix[i][j], matrix[j][i]);
			}
		}
		// �����ᷭת
		for (int i = 0; i < n; ++i) {
			for (int j = 0, k = n - 1; j < k; j++, k--) {
				swap(matrix[i][j], matrix[i][k]);
			}
		}
	}
};