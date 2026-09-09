class Solution {
public:
    long long countCommas(long long n) {
        if (n < 1000) return 0;
        long long ans = 0;
        
        for (int d = 4; ; d++) {
            long long lowerlimit = 1;
            for (int i = 0; i < d - 1; i++) lowerlimit *= 10;

            if (lowerlimit > n) break;
            
            long long upperlimit = 1;
            for (int j = 0; j < d; j++) upperlimit *= 10;
            
            long long count = min(n, upperlimit - 1) - lowerlimit + 1;
            long long commasPerNumber = (d - 1) / 3;
            
            ans += count * commasPerNumber;
        }
        
        return ans;
    }
};