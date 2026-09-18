class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        vector<int>missing;
        unordered_map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }
        for(int i=lower;i<=upper;i++){
            
            if(mp.find(i)==mp.end()){
                missing.push_back(i);
            }
        }
         vector<vector<int>>ans;
        if(missing.empty())return ans;
       
        int start=missing[0];
    
        for(int i=0;i<missing.size()-1;i++){
           
            if(missing[i]+1!=missing[i+1]){
            
             ans.push_back({start,missing[i]});
          
             start=missing[i+1];
            
            }
        }
        ans.push_back({start,missing.back()});
        return ans;
    }
};