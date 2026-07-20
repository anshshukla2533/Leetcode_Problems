class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int>temp;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                temp.push_back(grid[i][j]);
            }
        }
        vector<int>right(m*n,0);
        for(int i=0;i<m*n;i++){
            right[(i+k)%(m*n)]=temp[i];
        }
        for(int i=0;i<m*n;i++){
            grid[i/n][i%n]=right[i];
        }
        return grid;
    }
};