class Solution {
public:
    int t[1001];
    int solve(int i,string &s){
        int n=s.size();
        if (i == n) return 1;
        if(t[i]!=-1)return t[i];
        if(i>n)return 0;
        if(s[i]=='0')return 0;
         int result=solve(i+1,s);
         if(i+1<n){
            if(s[i]=='1' || (s[i]=='2' && s[i+1]<='6')){
            result+=solve(i+2,s);
            }
         }
         return t[i]=result;
    }
    int numDecodings(string s) {
        memset(t,-1,sizeof(t));
        return solve(0,s);
    }
};