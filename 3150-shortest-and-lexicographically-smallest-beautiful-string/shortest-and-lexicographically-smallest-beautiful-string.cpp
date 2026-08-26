class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        vector<string> ans;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            string temp = "";
            int cnt = 0;
            for (int j = i; j < n; j++) {
                if (s[j] == '1') cnt++; 
                temp += s[j];
                
                if (cnt == k) {
                    ans.push_back(temp);
                    break;
                }
            }
        }

        if (ans.empty()) return "";

        sort(ans.begin(), ans.end(), [](const string &a, const string &b) {
            if (a.size() == b.size()) return a < b;
            return a.size() < b.size();
        });

        return ans[0];
    }
};