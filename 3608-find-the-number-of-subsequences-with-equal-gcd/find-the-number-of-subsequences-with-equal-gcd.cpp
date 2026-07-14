class Solution {
public:
     int mod=1e9+7;
        int dp[201][201][201];
    int solve(vector<int>&nums,int i,int first,int second){
        if(i==nums.size()){
            if((first==second) && first!=0)return 1;
            return 0;
        }
        if(dp[i][first][second]!=-1)return dp[i][first][second];
        int skip=solve(nums,i+1,first,second);
        int take1=solve(nums,i+1,__gcd(first, nums[i]),second);
        int take2=solve(nums,i+1,first,__gcd(nums[i],second));
        dp[i][first][second]=((skip+take1)%mod+take2)%mod;
          return dp[i][first][second];
    }
    int subsequencePairCount(vector<int>& nums) {
        int n=nums.size()-1;
     
        memset(dp, -1, sizeof(dp));
     
        return solve(nums,0,0,0);
    }
};