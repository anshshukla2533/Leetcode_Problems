class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            if (a[0] == b[0]) return a[1] < b[1];
            return a[0] < b[0];
        });

        vector<vector<int>> ans;

        int prev_first = intervals[0][0];
        int prev_second = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {

            int first = intervals[i][0];
            int second = intervals[i][1];

            if (prev_second >= first) {
                prev_second = max(prev_second, second);
            } else {
                ans.push_back({prev_first, prev_second});
                prev_first = first;
                prev_second = second;
            }
        }

        ans.push_back({prev_first, prev_second});

        return ans;
    }
};