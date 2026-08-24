class Solution {
public:
     int solve(int i,vector<int>&prefix,vector<int>&dp){
        if(i==prefix.size()-1){
            return prefix[i];
        }
        if(dp[i]!=INT_MIN)return dp[i];
        int take=prefix[i]-solve(i+1,prefix,dp);
        int skip=solve(i+1,prefix,dp);
        dp[i] =max(take,skip);
        return dp[i];

     }
    int stoneGameVIII(vector<int>& stones) {
        int n=stones.size();
        vector<int>dp(n,INT_MIN);
      //  dp[0]=max(0,stones[0]);
        vector<int>prefix(n,0);
        prefix[0]=stones[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+stones[i];
        }
        //return solve(1,prefix,dp);
        //bottom up;
        dp[n - 1] = prefix[n - 1];

        for(int i=n-2;i>=1;i--){
            dp[i]=max(dp[i+1],prefix[i]-dp[i+1]);
        }
        return dp[1];
    }
};