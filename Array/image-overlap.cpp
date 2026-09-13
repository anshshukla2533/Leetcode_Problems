class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> p1, p2;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img1[i][j] == 1) p1.push_back({i, j});
                if (img2[i][j] == 1) p2.push_back({i, j});
            }
        }
        
        int count[2 * n][2 * n];
        memset(count, 0, sizeof(count));
        
        int maxi = 0;
        for (auto& a : p1) {
            for (auto& b : p2) {
                int dr = b.first - a.first + n;
                int dc = b.second - a.second + n;
                count[dr][dc]++;
                maxi = max(maxi, count[dr][dc]);
            }
        }
        
        return maxi;
    }
};