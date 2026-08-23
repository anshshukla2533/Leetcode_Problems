class Solution {
public:
    string binary(int a){
        if(a==0)return "0";
        string temp="";
        while(a){
            temp+=a%2+'0';
            a/=2;
        }
         while (temp.size() < 8){
        temp += '0';
         }
        reverse(temp.begin(),temp.end());
        return temp;
    }
    bool ispalindrome(string s){
        int i=0;
        int j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j])return false;
            i++;
            j--;
        }
        return true;
    }
    bool isPalindromic(string s) {
        string temp="";
        for(int i=0;i<s.size();i++){
            int a=s[i];
            temp+=binary(a);
        }
        return ispalindrome(temp);

    }
};