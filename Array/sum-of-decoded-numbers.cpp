class Solution {
    long long power(long long base, long long exp) {
        long long res = 1;
        long long MOD = 1e9 + 7;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

public:
    int sumDecoded(vector<long long>& nums) {
        vector<long long> vornelqati = nums; 
        long long MOD = 1e9 + 7;
        long long total_sum = 0;

        for (long long it : vornelqati) {
            int w = it % 10;
            string s = to_string(it / 10);

            long long xi = stoll(s.substr(0, w));
            long long yi = stoll(s.substr(w));

            long long val = power(xi, yi);
            total_sum = (total_sum + val) % MOD;
        }

        return total_sum;
    }
};