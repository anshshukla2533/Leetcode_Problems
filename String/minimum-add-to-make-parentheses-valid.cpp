class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans=0;
        int bal=0;
        stack<char>st;
        for(auto it:s){
          if(it=='(')bal++;
          else{
            if(bal>0)bal--;
            else ans++;
          }
        }
        return ans+bal;
    }
};