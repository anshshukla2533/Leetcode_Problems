class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int ans =0;

        for (int i = 0; i < n; i++) {
            unordered_map<int, int> mp;
            long long s = 0;

            for (int j = i; j < n; j++) {
                s += nums[j];

                int double_rem = ((2LL * nums[j]) % k + k) % k;
                mp[double_rem]++;

                int rem = (s % k + k) % k;

                if (rem == 0 || mp.find(rem) != mp.end()) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};