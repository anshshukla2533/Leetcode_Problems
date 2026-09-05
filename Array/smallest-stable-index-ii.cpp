class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>maxnum(n,0);
        vector<int>minnum(n,0);
        maxnum[0]=nums[0];
        minnum[n-1]=nums[n-1];
        int maxi=nums[0];
        int mini=nums[n-1];
        for(int i=1;i<n;i++){
            maxi=max(maxi,nums[i]);
            maxnum[i]=maxi;
        }
        for(int j=n-2;j>=0;j--){
            mini=min(mini,nums[j]);
            minnum[j]=mini;
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            if(maxnum[i]-minnum[i]<=k){
                ans=min(ans,i);
            }
        }
        if(ans!=INT_MAX)return ans;
        return -1;
        
    }
};