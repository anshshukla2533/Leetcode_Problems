class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mini=min_element(nums.begin(),nums.end())-nums.begin();
        int maxi=max_element(nums.begin(),nums.end())-nums.begin();
        int n=nums.size();
        int i=min(mini,maxi);
        int j=max(mini,maxi);
        return min({j+1,(n-i),((i+1)+(n-j))});

    }
};