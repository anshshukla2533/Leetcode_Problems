class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    bool canCommunicate = false;
                    
                    // Traverse same column
                    for(int r = 0; r < m; r++) {
                        if(r != i && grid[r][j] == 1) {
                            canCommunicate = true;
                            break;
                        }
                    }
                    
                    // Traverse same row (if not already found)
                    if(!canCommunicate) {
                        for(int k = 0; k < n; k++) {
                            if(k != j && grid[i][k] == 1) {
                                canCommunicate = true;
                                break;
                            }
                        }
                    }
                    
                    if(canCommunicate) {
                        ans++;
                    }
                }
            }
        }
        
        return ans;
    }
};