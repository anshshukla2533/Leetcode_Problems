class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int v=points.size();
        vector<vector<pair<int, int>>> adj(v);
        for (int i = 0; i < v; i++) {
            for (int j = i + 1; j < v; j++) {
                int wt = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj[i].push_back({j, wt});
                adj[j].push_back({i, wt});
            }
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>vis(v,0);
        pq.push({0,0});//wt node
        int sum=0;
        while(!pq.empty()){
            auto f=pq.top();
            pq.pop();
            int wt=f.first;
            int node=f.second;
            if(vis[node])continue;
            vis[node]=1;
            sum+=wt;
            for(auto it:adj[node]){
                if(!vis[it.first]){
                    pq.push({it.second,it.first});
                }
            }
        }
        return sum;
    }
};