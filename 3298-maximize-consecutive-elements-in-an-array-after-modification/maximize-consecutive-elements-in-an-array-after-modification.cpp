class Solution {
public:
    int n;
    int dp[100005][2];

    int findval(int start, vector<int>& nums, int target) {
        int j = lower_bound(nums.begin() + start, nums.end(), target) - nums.begin();

        if (j < n && nums[j] == target)
            return j;

        return -1;
    }

    int solve(int i, int inc, vector<int>& nums) {
        if (i >= n) return 0;

        if (dp[i][inc] != -1)
            return dp[i][inc];

        int curVal = nums[i] + inc;
        int len = 1;

        // Option 1: Find curVal + 1
        int j = findval(i + 1, nums, curVal + 1);
        if (j != -1) {
            len = max(len, 1 + solve(j, 0, nums));
        }

        // Option 2: Find curVal and increment it
        j = findval(i + 1, nums, curVal);
        if (j != -1) {
            len = max(len, 1 + solve(j, 1, nums));
        }

        return dp[i][inc] = len;
    }

    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        n = nums.size();
        memset(dp, -1, sizeof(dp));

        int ans = 1;

        for (int i = 0; i < n; i++) {
            ans = max(ans, solve(i, 0, nums));
            ans = max(ans, solve(i, 1, nums));
        }

        return ans;
    }
};