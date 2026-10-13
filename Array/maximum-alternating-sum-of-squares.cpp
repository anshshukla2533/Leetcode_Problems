class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums[i]=nums[i]*nums[i];
        }
        sort(nums.begin(),nums.end());
        long long s1=accumulate(nums.begin(),nums.begin()+n/2,0LL);
        long long s2=accumulate(nums.begin()+n/2,nums.end(),0LL);
        return s2-s1;
    }
};