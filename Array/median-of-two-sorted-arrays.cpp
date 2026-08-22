class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      vector<int>arr;
      int i=0;
      int j=0;
      int n=nums1.size();
      int m=nums2.size();
      int k=n+m;
       
      while(i<n && j<m){
        if(nums1[i]<nums2[j]){
            arr.push_back(nums1[i]);
            i++;
        }else{
            arr.push_back(nums2[j]);
            j++;
        }
      }
      while(i<n){
        arr.push_back(nums1[i++]);
      }
      while(j<m){
        arr.push_back(nums2[j++]);
      }
      if (k&1)return arr[(k)/2];
      return (arr[k/2]+arr[k/2-1])/2.0;
        
    }
};