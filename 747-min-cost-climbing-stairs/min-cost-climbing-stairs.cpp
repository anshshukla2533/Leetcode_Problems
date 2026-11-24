class Solution {
public:
    int f(int i, vector<int>& cost, vector<int>& dp) {
        int n = cost.size();
        if (i >= n) return 0;
        if (dp[i] != -1) return dp[i];

        int one =cost[i] + f(i + 1, cost, dp);
        int two =cost[i] + f(i + 2, cost, dp);
        return dp[i] =  min(one, two);
    }

    int minCostClimbingStairs(vector<int>& cost) {
       int n = cost.size();
        vector<int> dp(n + 1, 0);
        // dp[0] = 0 and dp[1] = 0 because we can start at index 0 or 1 for free
        for (int i = 2; i <= n; i++) {
            int one = dp[i - 1] + cost[i - 1];
            int two = dp[i - 2] + cost[i - 2];
            dp[i] = min(one, two);
        }
        return dp[n];
    }
};