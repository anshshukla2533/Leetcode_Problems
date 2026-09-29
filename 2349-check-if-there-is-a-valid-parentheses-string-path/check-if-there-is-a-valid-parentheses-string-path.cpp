class Solution {
public:
    int m, n;
    int dp[101][101][201];

    bool solve(vector<vector<char>>& grid, int row, int col, int op, int cl) {
        if (grid[row][col] == '(') op++;
        else cl++;

        if (cl > op) return false;

        if (row == m - 1 && col == n - 1) {
            return op == cl;
        }

        int balance = op - cl;
        if (dp[row][col][balance] != -1) return dp[row][col][balance];

        bool down = (row + 1 < m) ? solve(grid, row + 1, col, op, cl) : false;
        bool right = (col + 1 < n) ? solve(grid, row, col + 1, op, cl) : false;

        return dp[row][col][balance] = (down || right);
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        if ((m + n - 1) % 2 != 0) return false;

        memset(dp, -1, sizeof(dp));
        return solve(grid, 0, 0, 0, 0);
    }
};