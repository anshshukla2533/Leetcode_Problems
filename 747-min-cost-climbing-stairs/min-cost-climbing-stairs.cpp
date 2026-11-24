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
        vector<int> dp(n, -1);
        return min(f(0, cost, dp), f(1, cost, dp));
    }
};