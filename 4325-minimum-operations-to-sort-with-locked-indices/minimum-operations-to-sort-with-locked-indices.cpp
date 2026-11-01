class Solution {
public:
    bool isort(vector<int> nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) return false;
        }
        return true;
    }

    int minOperations(vector<int>& nums, vector<int>& locked, int k) {
        int op = 0;

        while (!isort(nums)) {
          //  bool swapped = false;

            for (int i = 0; i < nums.size() - 1; i++) {
                if (nums[i] > nums[i + 1]) {

                    if (locked[i] == 1) {
                        if (k == 0) return -1;
                        locked[i] = 0;
                        k--;
                        op++;
                    }

                    if (locked[i + 1] == 1) {
                        if (k == 0) return -1;
                        locked[i + 1] = 0;
                        k--;
                        op++;
                    }

                    swap(nums[i], nums[i + 1]);
                    op++;
                   // swapped = true;
                }
            }

           // if (!swapped) break;
        }

        return op;
    }
};