class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
       int low=0;
       int high=nums.size()-2;
       while(low<=high){
        int mid=(low+high)>>1;
        if(nums[mid]==nums[mid^1]){
            low=mid+1;
        }else{
            high=mid-1;
        }
       }
       return nums[low];
       
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna