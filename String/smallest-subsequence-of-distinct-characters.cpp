class Solution {
public:
    string smallestSubsequence(string s) {
       string res="";
       vector<int>lastidx(26,0);
       vector<bool>pre(26,false);
       for(int i=0;i<s.size();i++){
        lastidx[s[i]-'a']=i;
       }
       for (int i = 0; i < s.size(); i++) {

    if (pre[s[i]-'a'])
        continue;

    while (!res.empty() &&
           res.back() > s[i] &&
           lastidx[res.back()-'a'] > i) {

        pre[res.back()-'a'] = false;
        res.pop_back();
    }

    res.push_back(s[i]);
    pre[s[i]-'a'] = true; 
}
       return res;
        
    }
};