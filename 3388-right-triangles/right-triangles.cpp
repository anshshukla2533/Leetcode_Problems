class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        long long ans = 0;
        
        vector<int> row_cnt(n, 0);
        vector<int> col_cnt(m, 0);
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    row_cnt[i]++;
                    col_cnt[j]++;
                }
            }
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    ans += (long long)(row_cnt[i] - 1) * (col_cnt[j] - 1);
                }
            }
        }
        
        return ans;
    }
};