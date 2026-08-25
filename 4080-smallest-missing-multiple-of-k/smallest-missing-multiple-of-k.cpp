class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
    
       unordered_map<int,int>mp;
       for(auto it:nums){
        mp[it]++;
       }
       int ans=k;
    
       while(true){
        if(mp.find(ans)!=mp.end())ans+=k;
        else {
            return ans;
            
        }
       }
       return ans;
    }
};
