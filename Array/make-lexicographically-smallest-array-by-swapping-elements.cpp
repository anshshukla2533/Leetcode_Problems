class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
     int n=nums.size();
     vector<pair<int,int>>mp;
    for(int i=0;i<n;i++){
        mp.push_back({nums[i],i});
    }
    sort(mp.begin(),mp.end());
    vector<int>ans(n,0);
    int i=0;
    while(i<n){
        int j=i;
        while(j+1<n && mp[j+1].first-mp[j].first<=limit){
            j++;
        }
        vector<int>ind;
        for(int k=i;k<=j;k++){
            ind.push_back(mp[k].second);
        }
        sort(ind.begin(),ind.end());
        for(int k=0;k<ind.size();k++){
            ans[ind[k]]=mp[k+i].first;
        }
        i=j+1;
    }

       return ans;
    }
};