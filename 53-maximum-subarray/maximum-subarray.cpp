class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum=0;
        int n=nums.size();
        if(n==1)return nums[0];
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            maxsum=maxsum+nums[i];
             maxi=max(maxi,maxsum);
            if(maxsum<0)maxsum=0;
           
        }
        return maxi;
    }
};