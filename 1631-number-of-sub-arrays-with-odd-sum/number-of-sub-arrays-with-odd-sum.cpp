class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
       int odd_cnt=0;
       int even_cnt=1;
       int total=0;
       int mod=1e9+7;
       int cs=0;
       for(int num:arr){
           cs+=num;
           if(cs%2!=0){
            total=(total+even_cnt)%mod;
            odd_cnt++;
           }else{
           total=(total+odd_cnt)%mod;
           even_cnt++;
           }
       }
       return total%mod;

    }
};