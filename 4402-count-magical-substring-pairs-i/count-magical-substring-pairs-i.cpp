class Solution {
public:
    int countMagicalPairs(string s) {
        int n = s.size();
        long long ans = 0;

        for (int j = 0; j < n - 1; j++) {

            vector<int> leftDistinct;
            vector<int> freq(26, 0);
            int distinct = 0;

            for (int i = j; i >= 0; i--) {
                if (freq[s[i] - 'a'] == 0)
                    distinct++;
                freq[s[i] - 'a']++;
                leftDistinct.push_back(distinct);
            }

            unordered_map<int, int> cnt;
            fill(freq.begin(), freq.end(), 0);
            distinct = 0;

            // s[j+1..k]
            for (int k = j + 1; k < n; k++) {
                if (freq[s[k] - 'a'] == 0)
                    distinct++;
                freq[s[k] - 'a']++;
                cnt[distinct]++;
            }

            for (int x : leftDistinct)
                ans += cnt[x];
        }

        return ans;
    }
};