class Solution {
public:
     int mod=1e9+7;
        /*
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

 */


    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());

        static int dp[201][201][201];
        memset(dp, 0, sizeof(dp));

        for(int first = 1; first <= mx; first++) {
            dp[n][first][first] = 1;
        }

        for(int i = n - 1; i >= 0; i--) {

            for(int first = 0; first <= mx; first++) {

                for(int second = 0; second <= mx; second++) {

                    int skip = dp[i + 1][first][second];

                    int take1 =
                        dp[i + 1][__gcd(first, nums[i])][second];

                    int take2 =
                        dp[i + 1][first][__gcd(second, nums[i])];

                    dp[i][first][second] =
                        ((skip + take1) % mod + take2) % mod;
                }
            }
        }

        return dp[0][0][0];
    }
};