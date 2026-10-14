class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int maxlen = 0;

        for (auto it : st) {
            if (!st.count(it - 1)) {

                int cur = it;
                int len = 1;
                while (st.count(cur + 1)) {
                    cur++;
                    len++;
                }

                maxlen = max(maxlen, len);
            }
        }

        return maxlen;
    }
};