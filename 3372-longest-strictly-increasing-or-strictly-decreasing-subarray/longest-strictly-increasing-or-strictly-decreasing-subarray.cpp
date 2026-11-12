class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int l = 1;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            bool inc = true;
            bool de = true;
            for (int j = i; j < n - 1; j++) {
                if (nums[j] >= nums[j + 1]) inc = false;
                if (nums[j] <= nums[j + 1]) de = false;
                
                if (!inc && !de) break;
                
                if (inc || de) {
                    l = max(l, j - i + 2);
                }
            }
        }
        return l;
    }
};