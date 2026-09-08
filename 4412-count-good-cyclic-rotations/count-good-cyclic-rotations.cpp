class Solution {
public:
      
    int countGoodRotations(vector<int>& nums) {
    
        long long  total_sum=accumulate(nums.begin(),nums.end(),0LL);
        int n=nums.size();
        long long  firstsum=0;
        long long  secondsum=0;
        for(int i=0;i<n/2;i++){
         firstsum+=nums[i];
        }
        secondsum=total_sum-firstsum;
         int ans=0;
         for(int i=0;i<n;i++){
            if(firstsum>secondsum)ans++;
            int mid=(i+(n/2))%n;
            firstsum+=nums[mid];
            secondsum-=nums[mid];
            firstsum-=nums[i];
            secondsum+=nums[i];
         }
         return ans;
        
    }
};