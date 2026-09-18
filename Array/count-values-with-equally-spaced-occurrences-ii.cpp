class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,pair<int,vector<int>>>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].first++;
            mp[nums[i]].second.push_back(i);
        }
        int cnt=0;
        for(auto it:mp){
            int ct=it.second.first;
            vector<int>temp=it.second.second;
            bool correct=false;
            if(ct>=3){
                int diff=temp[1]-temp[0];
                for(int i=2;i<temp.size();i++){
                    correct=true;
                    if(temp[i]-temp[i-1]!=diff){
                        correct=false;
                        break;
                    }
                }
            }
            if(correct)cnt++;
        }
        return cnt;
    }
};