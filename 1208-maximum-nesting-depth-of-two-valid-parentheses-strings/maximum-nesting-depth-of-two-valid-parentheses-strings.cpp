class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n=seq.size();
        vector<int>ans(n,0);
        stack<char>st;
        for(int i=0;i<seq.size();i++){
            if(seq[i]=='('){
                st.push('(');
                ans[i]=(st.size()%2)?1:0;
            }else{
               ans[i]=(st.size()%2)?1:0;
               st.pop();
            }
        }
        return ans;
    }
};