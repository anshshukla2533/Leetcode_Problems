class Solution {
public:
    bool isValid(string s) {

        stack<char>st;
        
        for(char it:s){
            if(it=='(' || it=='{' || it=='['){
                st.push(it);
            }else if(it==')'){
                if(st.empty())return false;
                if(st.top()!='(')return false;
                st.pop();
            }else if(it=='}'){
                if(st.empty())return false;
                if(st.top()!='{')return false;
                st.pop();
            }else if(it==']'){
                if(st.empty())return false;
                if(st.top()!='[')return false;
                st.pop();
            }
        }
        return st.empty();
        return true;
    }
};