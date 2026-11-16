class Solution {
public:
    string digitSum(string s, int k) {
        int ans=0;
        int num=0;
       
        // string temp="";
        int len=0;
        while(s.length()>k){
            string t="";
           for(int i=0;i<s.length();i+=k){
             int temp=0;
            for(int j=i;j<i+k&& j<s.size();j++){
                temp+=s[j]-'0';
            } 
            t+=to_string(temp);
           }
           s=t;

        }
        return s;
    }
};