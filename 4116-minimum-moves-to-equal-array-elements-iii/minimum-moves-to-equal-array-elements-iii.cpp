class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mini=*max_element(nums.begin(),nums.end());
        int ans=0;
        for(auto it:nums){
            ans+=abs(it-mini);
        }
        return ans;
    }
};