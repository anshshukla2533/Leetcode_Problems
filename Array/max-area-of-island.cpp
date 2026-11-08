class Solution {
public:
    int dfs(vector<vector<int>>& grid, int row, int col) {
        int m = grid.size();
        int n = grid[0].size();

        if (row < 0 || col < 0 || row >= m || col >= n || grid[row][col] == 0) {
            return 0;
        }
 
        grid[row][col] = 0;
        return 1 + dfs(grid, row + 1, col)
                 + dfs(grid, row - 1, col)
                 + dfs(grid, row, col + 1)
                 + dfs(grid, row, col - 1);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    ans = max(ans, dfs(grid, i, j));
                }
            }
        }
        return ans;
    }
};