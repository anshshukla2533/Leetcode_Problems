class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0;
        int j=numbers.size()-1;
        while(i<=j){
            int val=numbers[i]+numbers[j];
            if(val==target){
                return {i+1,j+1};
            }
            if(val<target /*|| (numbers[i]==numbers[i+1])*/){
                i++;
            }else if(val>target /*|| (numbers[j]==numbers[j-1])*/){
                j--;
            }
        }
        return {};
    }
};