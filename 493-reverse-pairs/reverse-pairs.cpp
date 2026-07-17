class Solution {
public:
    int cnt = 0;

    void merge(vector<int>& nums, int low, int mid, int high) {
        vector<int> temp;
        int left = low;
        int right = mid + 1;

        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left]);
                left++;
            } else {
                temp.push_back(nums[right]);
                right++;
            }
        }

        while (left <= mid) {
            temp.push_back(nums[left]);
            left++;
        }

        while (right <= high) {
            temp.push_back(nums[right]);
            right++;
        }

        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }
    }

    void countpairs(vector<int>& nums, int l, int mid, int h) {
        int right = mid + 1;

        for (int left = l; left <= mid; left++) {
            while (right <= h &&
                   (long long)nums[left] > 2LL * nums[right]) {
                right++;
            }
            cnt += right - (mid + 1);
        }
    }

    void mergesort(vector<int>& nums, int l, int h) {
        if (l >= h)
            return;

        int mid = l + (h - l) / 2;

        mergesort(nums, l, mid);
        mergesort(nums, mid + 1, h);

        countpairs(nums, l, mid, h);
        merge(nums, l, mid, h);
    }

    int reversePairs(vector<int>& nums) {
        cnt = 0;
        mergesort(nums, 0, nums.size() - 1);
        return cnt;
    }
};