class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int left = 0;
        int maxlen = 0;
        unordered_map<int, int> mp;

        for (int right = 0; right < nums.size(); right++) {
            mp[nums[right]]++;

            while (mp[nums[right]] > k) {
                mp[nums[left]]--;
                left++;
            }

            maxlen = max(maxlen, right - left + 1);
        }

        return maxlen;
    }
};