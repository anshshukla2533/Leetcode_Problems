class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1=s1.size();
        int n2=s2.size();
        if(n1>n2)return false;
        vector<int>freq1(26,0);
        vector<int>freq2(26,0);
        for(char ch:s1){
            freq1[ch-'a']++;
        }
        for(int i=0;i<n2;i++){
          freq2[s2[i]-'a']++;
          if(i>=n1){
             freq2[s2[i-n1]-'a']--;
          }
          if(i>=n1-1 && freq1==freq2){
            return true;
          }
        }
        return false;
    }
};