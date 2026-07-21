class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans=1;
        int temp=1;
        if(nums.size()<1)return 0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]-nums[i]==1)temp++;
            else if(nums[i+1]-nums[i]<1)continue;
            else temp=1;
            ans=max(ans,temp);
        }

        return ans;
    }
};