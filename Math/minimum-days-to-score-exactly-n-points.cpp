class Solution {
public:
    int solve(int current_score, int target, vector<int>& memo) {
        if (current_score == target) return 0;
        if (current_score > target) return 1e9;
        
        if (memo[current_score] != -1) {
            return memo[current_score];
        }
        int min_days = 1e9;
        for (long long L = 1; ; ++L) {
            long long points = (L * (L + 1)) / 2;
            if (current_score + points > target) break;
            int next_days = (current_score + points == target) ? 0 : 1;
            
            int res = L + next_days + solve(current_score + points, target, memo);
            min_days = min(min_days, res);
        }

        return memo[current_score] = min_days;
    }

    int minDays(int n) {
        vector<int> memo(n + 1, -1);
        return solve(0, n, memo);
    }
};