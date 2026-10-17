class Solution {
public:
    int digit(int num) {
        int sum = 0;
        while (num) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        vector<int> t = nums;

        auto cmp = [&](int a, int b) {
            int s1 = digit(a);
            int s2 = digit(b);

            if (s1 != s2)
                return s1 < s2;
            return a < b;
        };

        sort(t.begin(), t.end(), cmp);

        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]] = i;      
        }

        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == t[i]) continue;

            int idx = mp[t[i]];    

            swap(nums[i], nums[idx]);

            mp[nums[idx]] = idx;   
            mp[nums[i]] = i;

            ans++;
        }

        return ans;
    }
};