class Solution {
public:
    int dividecon(vector<int>&nums,int low,int high){
      if(low==high)return nums[low];
      int mid=(low+high)/2;
      int leftmax=dividecon(nums,low,mid);
      int rightmax=dividecon(nums,mid+1,high);
      int sum=0;
      int leftSum=INT_MIN;
       for(int i = mid; i >= low; i--) {
            sum += nums[i];
            leftSum = max(leftSum, sum);
        }


  
        sum = 0;
        int rightSum = INT_MIN;

        for(int i = mid + 1; i <= high; i++) {
            sum += nums[i];
            rightSum = max(rightSum, sum);
        }
        int crossmax=rightSum+leftSum;
      return max({leftmax,rightmax,crossmax});
    }
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
        int ans=dividecon(nums,0,n-1);
        return ans;
    }
};