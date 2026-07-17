class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(auto it:nums){
            freq[it]++;
        }
        int n=nums.size();
        for(auto it:freq){
            if(it.second>n/2)return it.first;
        }
        return {};
    }
};