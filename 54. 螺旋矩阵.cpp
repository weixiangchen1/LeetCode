class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.empty())
            return ans;
        
        int row = 0, col = 0, right = matrix[0].size() - 1, low = matrix.size() - 1;
        while (true) {
            for (int i = row; i <= right; ++i) {
                ans.push_back(matrix[col][i]);
            }
            col++;
            if (col > low) {
                break;
            }

            for (int i = col; i <= low; ++i) {
                ans.push_back(matrix[i][right]);
            }
            right--;
            if (right < row) {
                break;
            }
            
            for (int i = right; i >= row; --i) {
                ans.push_back(matrix[low][i]);
            }
            low--;
            if (low < col) {
                break;
            }

            for (int i = low; i >= col; --i) {
                ans.push_back(matrix[i][row]);
            }
            row++;
            if (row > right) {
                break;
            }
        }
        return ans;
    }
};
