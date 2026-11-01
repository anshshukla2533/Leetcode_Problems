class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>> pq;
        
        for (auto it : points) {
            int x = it[0];
            int y = it[1];
            int val = x * x + y * y;
            pq.push({val, {x, y}});
            
            if (pq.size() > k) {
                pq.pop();
            }
        }
        
        vector<vector<int>> ans;
        while (!pq.empty()) {
            auto el = pq.top();
            pq.pop();
            int x = el.second.first;
            int y = el.second.second;
            ans.push_back({x, y});
        }
        
        return ans;
    }
};