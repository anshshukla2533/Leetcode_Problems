class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        int n=nums.size();
        int i=0;
        while(i<n-2){
            if( i>0 && nums[i]==nums[i-1]){
                i++;
                continue;
            }
            int target=-nums[i];
            int st=i+1;
            int jt=n-1;
            while(st<jt){
                int s=nums[st]+nums[jt];
                if(s>target){
                    jt--;
                }else if(s<target){
                    st++;
                }
                else{
                      ans.push_back({nums[i], nums[st], nums[jt]});
                      while(st<jt && nums[st]==nums[st+1])st++;
                      while(st<jt && nums[jt]==nums[jt-1])jt--;
                      st++;
                      jt--;
                }
            }
            i++;
        }
        return ans;
        
    }
};