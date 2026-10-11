class Solution {
public:
    string removeOuterParentheses(string s) {
       int lv=0;
       string res="";
       for(auto it:s){
        if(it=='(' ){
            if(lv>0)res+=it;
            lv++;
        }else if(it==')'){
            lv--;
            if(lv>0)res+=it;
            
        }
       } 
       return res;
    }
};