class Solution {
public:
    int solve(int row,int col,int dp[101][101]){
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
        return solve(m-1,n-1,dp);
    }
};