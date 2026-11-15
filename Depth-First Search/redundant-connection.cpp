class Solution {
private:
    int find(int i, vector<int>& parent) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i], parent); 
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1);
        vector<int> rank(n + 1, 0);
        
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
        
        for (auto& edge : edges) {
            int rootU = find(edge[0], parent);
            int rootV = find(edge[1], parent);
            if (rootU == rootV) {
                return edge;
            }
            if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
        
        return {};
    }
};