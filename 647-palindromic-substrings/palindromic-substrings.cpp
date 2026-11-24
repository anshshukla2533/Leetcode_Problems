class Solution {
public:
   int t[1001][1001];
     bool solve(int i, int j, string &s) {
        if (i >= j)
            return 1;

        if (t[i][j] != -1)
            return t[i][j];

        if (s[i] == s[j])
            return t[i][j] = solve(i + 1, j - 1, s);

        return t[i][j] = 0;
    }

    int countSubstrings(string s) {
        int ans=0;
        int n=s.size();
        memset(t,-1,sizeof(t));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(solve(i,j,s)){
                    ans++;
                }
            }
        }
        return ans;
    }
};