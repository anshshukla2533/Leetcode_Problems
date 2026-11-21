class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = static_cast<int>(grid.size());
        vector<vector<uint8_t>> vis(n, vector<uint8_t>(n, 0));

    
        using State = tuple<int, int, int>;
        priority_queue<State, vector<State>, greater<State>> pq;

        pq.push({grid[0][0], 0, 0});
        vis[0][0] = 1;

        const int dx[4] = {0, 1, 0, -1};
        const int dy[4] = {1, 0, -1, 0};

        while (!pq.empty()) {
            auto [t, r, c] = pq.top();
            pq.pop();

            if (r == n - 1 && c == n - 1) {
                return t;
            }

            for (int k = 0; k < 4; ++k) {
                int nr = r + dx[k];
                int nc = c + dy[k];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !vis[nr][nc]) {
                    vis[nr][nc] = 1;
                    int nextTime = max(t, grid[nr][nc]);
                    pq.push({nextTime, nr, nc});
                }
            }
        }

        return -1;
    }
};