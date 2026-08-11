class Solution {
public:
    int missingInteger(vector<int>& nums) {

        unordered_map<int,int> num;

        for(int i = 0; i < nums.size(); i++)
            num[nums[i]] = i;

        int sum = nums[0];

        int i = 1;
        while(i < nums.size() && nums[i] == nums[i-1] + 1){
            sum += nums[i];
            i++;
        }

        while(num.find(sum) != num.end())
            sum++;

        return sum;
    }
};