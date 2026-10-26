class Solution {
public:
    long long dfs(vector<vector<int>>& grid, int row, int col) {
        int m = grid.size();
        int n = grid[0].size();
        
        
        if (row < 0 || row >= m || col < 0 || col >= n || grid[row][col] == 0) {
            return 0;
        }
        
        long long curval = grid[row][col];
        grid[row][col] = 0; 
        
        curval += dfs(grid, row + 1, col);
        curval += dfs(grid, row, col + 1);
        curval += dfs(grid, row - 1, col);
        curval += dfs(grid, row, col - 1);
        
        return curval;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] > 0) {
                    long long s = dfs(grid, i, j);
                    if (s % k == 0) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};