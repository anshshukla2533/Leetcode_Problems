class Solution {
public: 
     int maxlen;
     bool solve(int idx,string s,unordered_set<string>&st,int dp[]){
        if(idx==s.size())return true;
        if (dp[idx] != -1)
            return dp[idx];

        string temp="";
        for(int i=idx;i<s.size() && temp.size()<maxlen;i++){
            temp+=s[i];
            if(st.count(temp)){
                if(solve(i+1,s,st,dp))
                return dp[idx] = true;
            }
        }
        return dp[idx]=false;
     }
    bool wordBreak(string s, vector<string>& wordDict) {
        for (auto& it : wordDict) {
            maxlen = max(maxlen, (int)it.size());
        }
       // int dp[10001];
        //memset(dp,-1,sizeof(dp));
        unordered_set<string>st(wordDict.begin(),wordDict.end());

        int n = s.size();

        vector<bool> dp(n + 1, false);

        dp[0] = true;

        for (int i = 1; i <= n; i++) {

            for (int j = 0; j < i; j++) {

                if (dp[j] && st.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
      //  return solve(0,s,st,dp);
    }
};