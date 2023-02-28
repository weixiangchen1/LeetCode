class Solution {
public:
    int cnt = 0;

    void dfs(vector<vector<char>>& grid, int i, int j)
    {          
        grid[i][j] = '0';   
        int x_add[4] = { 1, -1, 0, 0};
        int y_add[4] = { 0, 0, 1, -1};
        for (int n = 0; n < 4; n++) {
            int x = i + x_add[n];
            int y = j + y_add[n];
            if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == '0')
                continue;  
            
            dfs(grid, x, y);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    cnt++;
                    dfs(grid, i, j);            
                }
            }
        }
        return cnt;
    }
};
