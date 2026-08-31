class Solution {
public:

  string reverseWords(string s) {
      string ans="";
      stack<string>st;
       string word="";
      for(char it:s){
          
          if(it==' '){
            if(!word.empty()){
                st.push(word);
                word="";
            }
          }else{
           word+=it;
          }
      }
      if (!word.empty()) {
            st.push(word);
        }

      while(!st.empty()){
        ans+=st.top();
        st.pop();
        
     if (!st.empty()) {
                ans += " ";
         }
       
      }
      return ans;
    }
};