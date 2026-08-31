class Solution {
public:
    string reverse1(string s) {
        int j = s.size() - 1;
        string temp = "";
        while (j >= 0) {
            temp += s[j];
            j--;
        }
        return temp;
    }

    string reverseWords(string s) {
       
        reverse(s.begin(), s.end());

        string ans = "";
        int i = 0;
        int n = s.size();

   
        while (i < n) {
           
            while (i < n && s[i] == ' ') {
                i++;
            }
            if (i >= n) break;

           
            string word = "";
            while (i < n && s[i] != ' ') {
                word += s[i];
                i++;
            }

           
            string reversedWord = reverse1(word);

          
            if (!ans.empty()) {
                ans += " ";
            }
            ans += reversedWord;
        }

        return ans;
    }
};