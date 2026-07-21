class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans=1;
     
          if(nums.size()<1)return 0;
        /* brute force approach
      
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]-nums[i]==1)temp++;
            else if(nums[i+1]-nums[i]<1)continue;
            else temp=1;
            ans=max(ans,temp);
        }
        */
               unordered_set<int> st(nums.begin(), nums.end());

        

        for (int num : st) {
            if (!st.count(num - 1)) {

                int curr = num;
                int len = 1;

                while (curr != INT_MAX && st.count(curr + 1)) {
                    curr++;
                    len++;
                }

                ans = max(ans, len);
            }
        }
       return ans;
    }
};