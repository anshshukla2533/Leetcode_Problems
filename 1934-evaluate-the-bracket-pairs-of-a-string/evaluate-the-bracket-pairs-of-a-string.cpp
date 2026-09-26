class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string>mp;
        for(auto it:knowledge){
            auto key=it[0];
            auto val=it[1];
            mp[key]=val;
        }
        int i=0;
        string res="";
        int n=s.size();
        while(i<s.size()){
            if(s[i]=='('){
                
               i++;
                int si=i;
                string temp="";
                while(i<n&& s[i]!=')'){
                 temp+=s[i];
                 i++;
                }
                i++;
            
                if(mp.find(temp)!=mp.end()){
                    string v=mp[temp];
                    res+=v;

                }else{
                    res+='?';
                }

            }else{
                res+=s[i];
                i++;
            }
        }
        return res;
    }
};