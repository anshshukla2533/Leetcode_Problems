class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans="";
        int n=num;
        int s=0;
        while(n-- && s<=sum){
         for(int i=9;i>=0;i--){
            if(i<=sum){
                ans+=i+'0';
                sum-=i;
                break;
            }
         }

        }
    
        return sum == 0 ? ans : "";
    }
};