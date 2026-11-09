class Solution {
public:
    
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
         queue<pair<int,int>>q;
         int freshcnt=0;
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }else if(grid[i][j]==1){
                    freshcnt++;
                }
            }
         }
         if(freshcnt==0)return 0;
         int ans=0;
         int dx[4]={0,1,0,-1};
         int dy[4]={1,0,-1,0};
         while(!q.empty()){
            int sz=q.size();
            bool rooted=false;
            for(int i=0;i<sz;i++){
                auto[r,c]=q.front();
                q.pop();
                for(int d=0;d<4;d++){
                    int nr=r+dx[d];
                    int nc=c+dy[d];

                    if(nr>=0 && nr<n && nc<m && nc>=0 && grid[nr][nc]==1 ){
                        grid[nr][nc]=2;
                        q.push({nr,nc});
                        freshcnt--;
                        rooted=true;
                    }
                }
            }
            if(rooted){
                ans++;
            }
         }

        return freshcnt == 0 ? ans : -1;
    }
};