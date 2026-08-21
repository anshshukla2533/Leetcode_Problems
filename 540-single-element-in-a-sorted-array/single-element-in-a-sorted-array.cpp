class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
       int x=0;
       for(auto it:nums){
        x^=it;
       }
       return x;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna