class Solution {
public:
    int solve(int i, int rem, const vector<vector<pair<int, int>>>& candidates, vector<vector<int>>& memo) {
        if (rem == 0) return 0;
        if (rem < 0 || i >= candidates.size()) return 1e9;

        if (memo[i][rem] != -1) return memo[i][rem];

   
        int ans = solve(i + 1, rem, candidates, memo);

        for (auto& [val, cost] : candidates[i]) {
            if (rem >= val) {
                ans = min(ans, cost + solve(i + 1, rem - val, candidates, memo));
            }
        }

        return memo[i][rem] = ans;
    }

    int minOperations(vector<int>& nums, int sum) {
    

        int n = nums.size();
        vector<vector<pair<int, int>>> candidates(n);

        for (int i = 0; i < n; ++i) {
            int x = nums[i];
            
         
            int val = x, ops = 0;
            while (val <= sum) {
                candidates[i].push_back({val, ops});
                val *= 2;
                ops++;
            }

        
            val = x / 2; ops = 1;
            while (val > 0) {
                candidates[i].push_back({val, ops});
                val /= 2;
                ops++;
            }
            candidates[i].push_back({0, ops});
        }

        vector<vector<int>> memo(n, vector<int>(sum + 1, -1));
        int res = solve(0, sum, candidates, memo);

        return res >= 1e9 ? -1 : res;
    }
};