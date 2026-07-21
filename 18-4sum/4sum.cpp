class Solution {
public:
    vector<vector<int>> ans;

    void threeSum(vector<int>& nums, int start, long long target, int first) {

        int n = nums.size();

        for (int i = start; i < n - 2; i++) {

            if (i > start && nums[i] == nums[i - 1])
                continue;

            long long need = target - nums[i];

            int st = i + 1;
            int jt = n - 1;

            while (st < jt) {

                long long sum = 1LL * nums[st] + nums[jt];

                if (sum < need) {
                    st++;
                }
                else if (sum > need) {
                    jt--;
                }
                else {

                    ans.push_back({first, nums[i], nums[st], nums[jt]});

                    while (st < jt && nums[st] == nums[st + 1]) st++;
                    while (st < jt && nums[jt] == nums[jt - 1]) jt--;

                    st++;
                    jt--;
                }
            }
        }
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());

        int n = nums.size();

        for (int i = 0; i < n - 3; i++) {

            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            threeSum(nums, i + 1, 1LL * target - nums[i], nums[i]);
        }

        return ans;
    }
};