class Solution {
public:
    int reverseDegree(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            int v=s[i]-'a';
            int val=(26-v)*(i+1);
            ans+=val;
        }
        return ans;
    }
};