class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
       // set<int>st;
      //  int n=nums.size();
        /*brute force
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                vector<int>temp;
                for(int k=j;k<n;k++){
                 int x = nums[i] ^ nums[j] ^ nums[k];
                 st.insert(x);
                }
            }
        }
        return st.size();
        */
        // better approach
        int n=nums.size();
        if(n<3)return n;
        int p=0;
        int cur=n;
        while(cur){
            cur>>=1;
            p++;
        }
        return 1<<p;
    }
};