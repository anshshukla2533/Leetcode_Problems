class Solution {
public:
    vector<int> getPrimeFactors(int n) {
        vector<int> factors;

        if (n % 2 == 0) {
            factors.push_back(2);
            while (n % 2 == 0)
                n /= 2;
        }

        for (int i = 3; i * i <= n; i += 2) {
            if (n % i == 0) {
                factors.push_back(i);
                while (n % i == 0)
                    n /= i;
            }
        }

        if (n > 1)
            factors.push_back(n);

        return factors;
    }

    int longestSubarray(vector<int>& nums, int k) {

        int n = nums.size();

        
        vector<vector<int>> primeFactors(n);

        for (int i = 0; i < n; i++)
            primeFactors[i] = getPrimeFactors(nums[i]);

        unordered_map<int, int> freq;

        int left = 0;
        int ans = 0;

        for (int right = 0; right < n; right++) {

        \
            for (int p : primeFactors[right])
                freq[p]++;
\
            while (freq.size() > k) {

                for (int p : primeFactors[left]) {
                    freq[p]--;

                    if (freq[p] == 0)
                        freq.erase(p);
                }

                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};