class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool> visited(n, false);
        vector<int> minDist(n, INT_MAX);

        pq.push({0, 0});
        minDist[0] = 0;

        int totalCost = 0;
        int edgesUsed = 0;

        while (!pq.empty() && edgesUsed < n) {
            auto [cost, u] = pq.top();
            pq.pop();

            if (visited[u]) continue;

            visited[u] = true;
            totalCost += cost;
            edgesUsed++;

            for (int v = 0; v < n; ++v) {
                if (!visited[v]) {
                    int dist = abs(points[u][0] - points[v][0]) +
                               abs(points[u][1] - points[v][1]);
                    if (dist < minDist[v]) {
                        minDist[v] = dist;
                        pq.push({dist, v});
                    }
                }
            }
        }

        return totalCost;
    }
};