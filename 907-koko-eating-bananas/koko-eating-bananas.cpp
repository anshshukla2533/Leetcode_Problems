class Solution {
public:
    long long hr(vector<int>& piles, int mid) {
        long long h = 0;
        for (int i = 0; i < piles.size(); i++) {
            h += (piles[i] + mid - 1) / mid; 
        }
        return h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int res = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (hr(piles, mid) <= h) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;  
            }
        }
        return res;
    }
};