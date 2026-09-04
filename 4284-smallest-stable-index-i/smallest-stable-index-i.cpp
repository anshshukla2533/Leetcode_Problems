class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>maxnum(n,0);
        maxnum[0]=nums[0];
        vector<int>minnum(n,0);
        minnum[n-1]=nums[n-1];
        for(int i=0;i<n;i++){
            int maxi=INT_MIN;
            int mini=INT_MAX;
            for(int j=0;j<=i;j++){
                maxi=max(maxi,nums[j]);
            }
            maxnum[i]=maxi;
            for(int j=n-1;j>=i;j--){
                mini=min(mini,nums[j]);
            }
            minnum[i]=mini;
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