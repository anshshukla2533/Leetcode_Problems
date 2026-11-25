class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        const int INF = 1e9;

        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, INF));

        // Base case
        for (int i = 0; i <= n; i++)
            dp[i][0] = 0;

        for (int i = n - 1; i >= 0; i--) {
            for (int amnt = 1; amnt <= amount; amnt++) {

                int take = INF;

                if (coins[i] <= amnt)
                    take = 1 + dp[i][amnt - coins[i]];

                int nottake = dp[i + 1][amnt];

                dp[i][amnt] = min(take, nottake);
            }
        }

        return dp[0][amount] >= INF ? -1 : dp[0][amount];
    }
};