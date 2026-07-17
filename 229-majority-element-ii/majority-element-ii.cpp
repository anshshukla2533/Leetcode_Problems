class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidate1 = 0, candidate2 = 0;
        int cnt1 = 0, cnt2 = 0;

        for (int it : nums) {
            if (it == candidate1) {
                cnt1++;
            }
            else if (it == candidate2) {
                cnt2++;
            }
            else if (cnt1 == 0) {
                candidate1 = it;
                cnt1 = 1;
            }
            else if (cnt2 == 0) {
                candidate2 = it;
                cnt2 = 1;
            }
            else {
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = 0;
        cnt2 = 0;

        for (int it : nums) {
            if (it == candidate1)
                cnt1++;
            else if (it == candidate2)
                cnt2++;
        }

        vector<int> ans;

        if (cnt1 > nums.size() / 3)
            ans.push_back(candidate1);

        if (cnt2 > nums.size() / 3)
            ans.push_back(candidate2);

        return ans;
    }
};