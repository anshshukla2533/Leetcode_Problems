#include <bits/stdc++.h>


using namespace std;

class Solution {
private:
    long long countValidAmounts(long long x, const vector<int>& coins) {
        int n = coins.size();
        long long total = 0;

     
        for (int mask = 1; mask < (1 << n); ++mask) {
            long long current_lcm = 1;
            int bits_set = 0;
            bool overflow = false;

            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    bits_set++;
                    
                   
                    long long g = __gcd(current_lcm, (long long)coins[i]);
                    long long next_lcm = (current_lcm / g) * coins[i];

                    if (next_lcm > x) { 
                        overflow = true;
                        break;
                    }
                    current_lcm = next_lcm;
                }
            }

            if (overflow) continue;

            if (bits_set % 2 == 1) {
                total += x / current_lcm;
            } else {
                total -= x / current_lcm;
            }
        }

        return total;
    }

public:
    long long findKthSmallest(vector<int>& coins, int k) {
        long long min_coin = *min_element(coins.begin(), coins.end());
        long long low = 1;
        long long high = min_coin * (long long)k;
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (countValidAmounts(mid, coins) >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};