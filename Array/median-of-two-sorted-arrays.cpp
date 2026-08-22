class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      vector<int>arr;
      int i=0;
      int j=0;
      int n=nums1.size();
      int m=nums2.size();
      int k=n+m;
      int req=k/2;
       
      while(i<n && j<m && arr.size()<=req){
        if(nums1[i]<nums2[j]){
            arr.push_back(nums1[i]);
            i++;
        }else{
            arr.push_back(nums2[j]);
            j++;
        }
      }
      while(i<n && arr.size()<=req){
        arr.push_back(nums1[i++]);
      }
      while(j<m && arr.size()<=req){
        arr.push_back(nums2[j++]);
      }
      if (k&1)return arr[req];
      return (arr[req]+arr[req-1])/2.0;
        
    }
};