class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       unordered_map<int,int>mp;
       for(auto it:nums){
        mp[it]++;
       }
       int n=nums.size();
       vector<vector<int>>bucket(n+1);
       for(auto [num,count]:mp){
        bucket[count].push_back(num);
       }
       vector<int>ans;
       for(int i=n;i>=0 && ans.size()<k; i--){
         for(auto it:bucket[i]){
            ans.push_back(it);
            if(ans.size()==k)break;
         }
       }
       return ans;
    }
};