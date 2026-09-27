class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
      map<pair<int, int>, int> mp;
      int base=0;
      for(int i=0;i<nums.size()-1;i++){
        if(nums[i]==nums[i+1])base++;
      }
      for(int i=0;i<nums.size()-1;i++){
        if(nums[i]!=nums[i+1]){
           int x = min(nums[i], nums[i + 1]);
           int y = max(nums[i], nums[i + 1]);
           mp[{x,y}]++;
        }
      }
      int g=0;
      for(auto it:mp){
       g=max(g,it.second);
      }
      return g+base;
    }
};