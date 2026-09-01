class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sr = -1, sc = -1;
        int cnt = 0;

        vector<vector<int>> id(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }
                if (classroom[i][j] == 'L') {
                    id[i][j] = cnt++;
                }
            }
        }

        int fullmask = (1 << cnt) - 1;

        vector<vector<vector<int>>> best(m, vector<vector<int>>(n, vector<int>(fullmask + 1, -1)));

       
        using State = tuple<int, int, int, int, int>;
        queue<State> q;

        q.push({sr, sc, 0, energy, 0});
        best[sr][sc][0] = energy;

        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};

        while (!q.empty()) {
            auto [r, c, mask, ne, steps] = q.front();
            q.pop();

            if (mask == fullmask) return steps;
            if (ne == 0) continue;

            for (int i = 0; i < 4; i++) {
                int nr = r + dx[i];
                int nc = c + dy[i];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n || classroom[nr][nc] == 'X') {
                    continue;
                }

                int newen = ne - 1;
                int newmask = mask;

                if (classroom[nr][nc] == 'L') {
                    newmask |= (1 << id[nr][nc]);
                }
                if (classroom[nr][nc] == 'R') {
                    newen = energy;
                }

                if (best[nr][nc][newmask] >= newen) {
                    continue;
                }

                best[nr][nc][newmask] = newen;
                q.push({nr, nc, newmask, newen, steps + 1});
            }
        }

        return -1;
    }
};