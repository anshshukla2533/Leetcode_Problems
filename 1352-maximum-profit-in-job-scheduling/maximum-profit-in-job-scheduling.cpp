class Solution {
public:
    int dp[50001];
    int getnext(vector<vector<int>>& arr,int indx,int endtime,int n){
        int result=n;
        int st=indx;
        int end=n-1;
        while(st<=end){
            int mid=(st+end)>>1;
            if(arr[mid][0]>=endtime){
                result=mid;
                end=mid-1;
            }else{
                st=mid+1;
            }
        }
        return result;
    }
    int solve(vector<vector<int>>& arr,int i,int n){
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        int nextjob=getnext(arr,i+1,arr[i][1],n);
        int taken=arr[i][2]+solve(arr,nextjob,n);
        int notaken=solve(arr,i+1,n);
        dp[i]=max(taken,notaken);
        return dp[i];
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=startTime.size();
        memset(dp,-1,sizeof(dp));
        vector<vector<int>>arr(n,vector<int>(3,0));
       
        for(int i=0;i<n;i++){
            int u=startTime[i];
            int v=endTime[i];
            int p=profit[i];
            arr[i][0]=u;
            arr[i][1]=v;
            arr[i][2]=p;
        }
         sort(arr.begin(),arr.end());
        return solve(arr,0,n);

    }
};