class Solution {
public:
    long long solve(string &s, string &t, int i, int j, vector<vector<long long>> &dp) {
        int n = s.size();
        int m = t.size();
        
        if (j == m) return 1;
        if (i == n) return 0;
        
        if (dp[i][j] != -1) return dp[i][j];
        
        if (s[i] == t[j]) {
            return dp[i][j] = solve(s, t, i + 1, j + 1, dp) + solve(s, t, i + 1, j, dp);
        } else {
            return dp[i][j] = solve(s, t, i + 1, j, dp);
        }
    }

    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, -1));
        return solve(s, t, 0, 0, dp);
    }
};