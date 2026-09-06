class Solution {
public:
   int  f(int index1,int index2,string s,string t ,vector<vector<int>>&dp){
    if(index2==0)return 1;
    if(index1==0)return 0;
    if(dp[index1][index2]!=-1)return dp[index1][index2];
    if(s[index1-1]==t[index2-1])return dp[index1][index2]=f(index1-1,index2-1,s,t,dp)+f(index1-1,index2,s,t,dp);
    return dp[index1][index2]=f(index1-1,index2,s,t,dp);
   }
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<double>>dp(n+1,vector<double>(m+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
       
        for(int index1=1;index1<=n;index1++){
            for(int index2=1;index2<=m;index2++){
                if(s[index1-1]==t[index2-1]) dp[index1][index2]=dp[index1-1][index2-1]+dp[index1-1][index2];
    else dp[index1][index2]=dp[index1-1][index2];
            }
        }
        return (int)dp[n][m];
    }
};