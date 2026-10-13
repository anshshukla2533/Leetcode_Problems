class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       unordered_map<int,int>mp;
       for(auto it:nums){
        mp[it]++;
       }
       vector<int>temp;
       for(auto it:mp){
        temp.push_back(it.first);
       }
       sort(temp.begin(),temp.end(),[&](int a,int b){
        return mp[a]>mp[b];
       });

       return vector<int>(temp.begin(), temp.begin() + k);



    }
};