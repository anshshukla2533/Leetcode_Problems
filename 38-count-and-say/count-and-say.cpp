class Solution {
public:
      vector<vector<int>>helper1(string s){
        vector<vector<int>>temp;
        int n=s.size();
        for(int i=0;i<s.length();i++){
            int cnt=1;
            while(i+1<n && s[i]==s[i+1]){
                i++;
                cnt++;
            }
           
            temp.push_back({s[i],cnt});

        }
        return temp;
      }


      string helper2(vector<vector<int>>temp){
        string ans="";
        for(auto it:temp){
            auto f=it[1];
            auto s=it[0];
            ans+=to_string(f);
            ans+=char(s);
        }
        return ans;
      }
    string countAndSay(int n) {
        string ans="1";
       
        for(int i=2;i<=n;i++){
            vector<vector<int>>temp=helper1(ans);
            ans=helper2(temp);
        }
        return ans;
        
    }
};