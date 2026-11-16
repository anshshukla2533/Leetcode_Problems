class Solution {
public:
    long long dfs(int u, const vector<vector<int>>& adj, const vector<int>& op, const vector<int>& score, long long& total_max) {
       
        if (adj[u].empty()) {
            return score[u];
        }
        
        long long sum_children = 0;
        long long min_child_dp = 1e18; 
        
        for (int v : adj[u]) {
            long long child_dp = dfs(v, adj, op, score, total_max);
            sum_children += child_dp;
            min_child_dp = min(min_child_dp, child_dp);
        }
        
        long long current_dp = score[u] + sum_children;
        if (op[u] == 1) {
            current_dp -= min_child_dp;
        } else {
            if (min_child_dp < 0) {
                current_dp -= min_child_dp;
            }
        }
        
        return current_dp;
    }

    long long maxScore(vector<int>& parent, vector<int>& op, vector<int>& score) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }
        
        long long dummy = 0;
        return dfs(0, adj, op, score, dummy);
    }
};