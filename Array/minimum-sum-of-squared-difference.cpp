

class Solution {
public:
    long long minSumSquareDiff(std::vector<int>& nums1, std::vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        unordered_map<int, long long> freq;
        long long total_k = (long long)k1 + k2;

        for (int i = 0; i < n; ++i) {
            int diff =abs(nums1[i] - nums2[i]);
            if (diff > 0) {
                freq[diff]++;
            }
        }

        priority_queue<int> pq;
        for (auto& pair : freq) {
            pq.push(pair.first);
        }
        while (total_k > 0 && !pq.empty()) {
            int curr = pq.top();
            pq.pop();

            long long count = freq[curr];
            long long needed = count;

            if (total_k >= needed) {
                total_k -= needed;
                freq[curr] = 0;
                freq[curr - 1] += count;
                if (curr - 1 > 0 && freq[curr - 1] == count) {
                    pq.push(curr - 1);
                }
            } else {
                freq[curr] -= total_k;
                freq[curr - 1] += total_k;
                if (curr - 1 > 0) {
                    pq.push(curr - 1);
                }
                total_k = 0;
            }
        }

        long long min_sum = 0;
        for (auto& pair : freq) {
            long long diff = pair.first;
            long long count = pair.second;
            min_sum += count * diff * diff;
        }

        return min_sum;
    }
};