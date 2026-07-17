class Solution {
public:
    int solve(int row,int col,int dp[101][101]){
        //memorization
        if(row==0 && col==0)return 1;
        if(row<0 || col<0 )return 0;
        if(dp[row][col]!=-1)return dp[row][col];
        int up=solve(row-1,col,dp);
        int left=solve(row,col-1,dp);
        dp[row][col]=up+left;
        return dp[row][col];
    }
    int uniquePaths(int m, int n) {
        int dp[101][101];
        memset(dp,-1,sizeof(dp));
        //tabulation
        dp[0][0]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0)continue;
                int down,right=0;
                 down=(i-1)>=0?dp[i-1][j]:0;
                 right=(j-1)>=0?dp[i][j-1]:0;
                dp[i][j]=down+right;
            }
        }
        return dp[m-1][n-1];
        
    }
};