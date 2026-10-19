class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> temp(n,0);
        stack<int>st;
        st.push(n-1);
        temp[n-1]=0;
        for(int i=n-2;i>=0;i--){
           while(!st.empty() && temperatures[i]>=temperatures[st.top()]){
            st.pop();
           }
        
           if(!st.empty()){
           temp[i]=st.top()-i;
           }
              st.push(i);
        }
        return temp;
    }
};