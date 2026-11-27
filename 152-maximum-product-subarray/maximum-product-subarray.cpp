class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];
        int prefix = 1;
        int suffix = 1;

        for (int i = 0; i < n; i++) {
            prefix *= nums[i];
            suffix *= nums[n - 1 - i];

            ans = max({ans, prefix, suffix});

            if (prefix == 0) prefix = 1;
            if (suffix == 0) suffix = 1;
        }

        return ans;
    }
};