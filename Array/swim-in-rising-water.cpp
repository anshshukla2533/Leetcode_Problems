class Solution {
public:
    bool possible(vector<vector<int>>& grid, int i, int j, int t, vector<vector<int>>& vis) {
        int n = grid.size();
        if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] > t || vis[i][j]) {
            return false;
        }
        if (i == n - 1 && j == n - 1) {
            return true;
        }

        vis[i][j] = true;
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};

        for (int k = 0; k < 4; k++) {
            int nr = dx[k] + i;
            int nc = dy[k] + j;
            if (possible(grid, nr, nc, t, vis)) {
                return true;
            }
        }
        return false;
    }

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int l = 0, r = n * n - 1, result = r;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            vector<vector<int>> vis(n, vector<int>(n, false));
            if (possible(grid, 0, 0, mid, vis)) {
                result = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return result;
    }
};