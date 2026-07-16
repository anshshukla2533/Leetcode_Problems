class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int maxi=nums[0];
        int n=nums.size();
        vector<int>prefix(n,0);
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            prefix[i]=__gcd(nums[i],maxi);
            
        }
        sort(prefix.begin(),prefix.end());
        int i=0;
        int j=n-1;
        long long  sum=0;
        while(i<j){
           sum+=__gcd(prefix[i],prefix[j]);
           i++;
           j--;
        }
        return sum;
    }
};