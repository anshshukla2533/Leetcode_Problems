class Solution {
public:
    bool canbemade(const unordered_map<int, int>& original_mp, int num) {
        unordered_map<int, int> mp = original_mp;
        while (num > 0) {
            int digit = num % 10;
            if (mp[digit] <= 0) {
                return false;
            }
            mp[digit]--;
            num /= 10;
        }
        return true;
    }

    int totalNumbers(vector<int>& digits) {
        unordered_map<int, int> original_mp;
        for (int d : digits) {
            original_mp[d]++;
        }
        
        int cnt = 0;
        for (int i = 100; i <= 999; i += 2) {
            if (canbemade(original_mp, i)) {
                cnt++;
            }
        }
        return cnt;
    }
};