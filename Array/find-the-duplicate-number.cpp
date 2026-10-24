class Solution {
public:
    int findDuplicate(vector<int>&arr) {
        vector<int>ans;
        for(int i=0;i<arr.size();i++){
            int idx=abs(arr[i])-1;
            if(arr[idx]>0){
                arr[idx]=-arr[idx];
            }else{
                return (abs(arr[i]));
            }
        }
        return {};
    }
};