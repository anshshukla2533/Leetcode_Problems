class Solution {
public:
    int minInsertions(string s) {
        int insertions = 0;
        int openBrackets = 0;
        int n = s.length();
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                openBrackets++;
            } else {
                if (i + 1 < n && s[i + 1] == ')') {
                    i++;
                } else {
                    insertions++;
                }
                
                if (openBrackets > 0) {
                    openBrackets--;
                } else {
                    insertions++;
                }
            }
        }
        
        insertions += (openBrackets * 2);
        return insertions;
    }
};