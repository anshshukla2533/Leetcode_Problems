class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero=0;
        int one=0;
        int two=0;
        for(auto it:nums){
            if(it==0)zero++;
            if(it==1)one++;
            if(it==2)two++;
        }
        for(int i=0;i<nums.size();i++){
            if(zero){
                nums[i]=0;
                zero--;
            }
            else if(!zero && one){
                nums[i]=1;
                one--;
            }
            else if(!zero && !one)nums[i]=2;
            
        }
    
    }
};