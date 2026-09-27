class Solution {
public:
    string reverseParentheses(string s) {
        int cnt = 0;
        for (char c : s) {
            if (c == '(') cnt++;
        }

        while (cnt--) {
            int lastOpen = -1;
            
           
            for (int i = 0; i < s.length(); i++) {
                if (s[i] == '(') {
                    lastOpen = i; 
                } else if (s[i] == ')' && lastOpen != -1) {
                    int firstClose = i;
                    reverse(s.begin() + lastOpen + 1, s.begin() + firstClose);
                    s.erase(s.begin() + firstClose);
                    s.erase(s.begin() + lastOpen);
                    
                    break; 
                }
            }
        }

        return s;
    }
};