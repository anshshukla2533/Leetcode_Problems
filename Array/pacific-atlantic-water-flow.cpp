class Solution {
public:
    void dfs(int r,int c,vector<vector<int>>&heights,int prev,vector<vector<bool>>&visited){
      
        int m = heights.size();
        int n = heights[0].size();
        if (r < 0 || c < 0 || r >= m || c >= n || visited[r][c] || prev > heights[r][c]) 
            return;
        visited[r][c]=true;
        dfs(r+1,c,heights,heights[r][c],visited);
        dfs(r-1,c,heights,heights[r][c],visited);
        dfs(r,c+1,heights,heights[r][c],visited);
        dfs(r,c-1,heights,heights[r][c],visited);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<bool>>pacific(m,vector<bool>(n,false));
        vector<vector<bool>>atlan(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            dfs(i,0,heights,heights[i][0],pacific);
            dfs(i,n-1,heights,heights[i][n-1],atlan);
        }

        for(int i=0;i<n;i++){
            dfs(0,i,heights,heights[0][i],pacific);
            dfs(m-1,i,heights,heights[m-1][i],atlan);
        }

        vector<vector<int>> result;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pacific[i][j] && atlan[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        
        return result;
    }
};