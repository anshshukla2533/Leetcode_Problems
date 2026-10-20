class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        int i = 0, j = 0;

        while (true) {
            vis[i][j] = true;

            int ni = i, nj = j;

            if (grid[i][j] == 'R') nj++;
            else if (grid[i][j] == 'L') nj--;
            else if (grid[i][j] == 'U') ni--;
            else ni++;

            if (ni < 0 || ni >= m || nj < 0 || nj >= n)
                return {i, j};

            if (vis[ni][nj])
                return {i, j};

            i = ni;
            j = nj;
        }
    }
};