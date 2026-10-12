class Solution {
public:
    bool isAnagram(string s, string t) {
       vector<int>vec1(26,0);
       for(char ch:s){
        vec1[ch-'a']++;
       }
       for(char ch:t){
        vec1[ch-'a']--;
       }
       for(int i=0;i<26;i++){
        if(vec1[i])return false;
       }
       return true;
    }
};