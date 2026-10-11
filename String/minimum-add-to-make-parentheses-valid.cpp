class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        
        for (char it : s) {
            if (it == '(') {
                st.push(it); 
            } else {
                
                if (!st.empty() && st.top() == '(') {
                    st.pop();
                } else {
                    st.push(it);
                }
            }
        }
        
        return st.size();
    }
};