class Solution {
public:
    int minMoves(vector<int>& nums) {
       int op=0;
       int minel=*min_element(nums.begin(),nums.end());
       for(int i=0;i<nums.size();i++){
        op+=abs(nums[i]-minel);
       }
       return op;
    }

};