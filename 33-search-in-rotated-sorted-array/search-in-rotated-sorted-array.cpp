class Solution {
public:
    int search(vector<int>& arr, int target) {
       int low=0;
       int high=arr.size()-1;
       int ans=-1;
       while(low<=high){
        int mid=(low+high)>>1;
        if (arr[mid]==target){
            ans=mid;
            break;
        }
        if(arr[low]<=arr[mid]){   //left is sort
            if(arr[low]<=target && target<=arr[mid]){
             high=mid-1;
            }else{
             low= mid+1;
            }
        }else{      //right is sorted
          if(arr[mid]<=target && target<=arr[high]){
          low=mid+1;
          }else{
          high=mid-1;
          }
        }
       }
       return ans;
    }
};