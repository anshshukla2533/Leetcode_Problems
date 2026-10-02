class Solution {
public:
     vector<string>temp;
     void solve(int n,int op,int cl,string ans) {
       
        if(ans.length()==2*n){
            temp.push_back(ans);
            return ;
        }
        
          if(op+1<=n){
            solve(n,op+1,cl,ans+'(');
          }
          if(cl+1<=op){
           solve(n,op,cl+1,ans+')');
          }
     }
    vector<string> generateParenthesis(int n) {
        ///temp.clear();
        solve(n,0,0,"");
        return temp;
    }
};