class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
     sort(nums1.begin(),nums1.end());
     int n=nums1.size();
     int min_val=nums1[0];
     if(min_val%2!=0)return true;
     for(auto it:nums1){
        if(it%2!=0)return false;
     }
     return true;


    }
};