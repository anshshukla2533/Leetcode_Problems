class Solution {
public:
    bool checkString(string s) {
        bool b=false;
        int pos=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='b'){
                b=true;
                pos=i;
                break;
            }
        }
        for(int i=pos;i<s.size();i++){
            if(s[i]=='a' && b)return false;
        }
        return true;
    }
};