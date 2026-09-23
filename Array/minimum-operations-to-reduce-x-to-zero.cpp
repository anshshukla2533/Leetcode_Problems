class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int target = total - x;
        if (target < 0) return -1;
        if (target == 0) return nums.size();
        unordered_map<int, int> mp;
        mp[0] = -1;
        int sum = 0;
        int longest = -1;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            if (mp.count(sum - target))
                longest = max(longest, i - mp[sum - target]);

            if (!mp.count(sum))
                mp[sum] = i;
        }

        return longest == -1 ? -1 : nums.size() - longest;
    }
};