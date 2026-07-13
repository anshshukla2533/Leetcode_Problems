class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";

        int minLen = to_string(low).size();
        int maxLen = to_string(high).size();

        vector<int> ans;

        for (int len = minLen; len <= maxLen; len++) {

            for (int i = 0; i + len <= s.size(); i++) {

                string temp = s.substr(i, len);
                int num = stoi(temp);

                if (num >= low && num <= high) {
                    ans.push_back(num);
                }
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};