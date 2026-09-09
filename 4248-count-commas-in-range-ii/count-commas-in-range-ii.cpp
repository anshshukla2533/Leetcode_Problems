class Solution {
public:
    long long countCommas(long long n) {
       long long ans=0;
       long long lower=1000;
       int cm=1;
       while(lower<=n){
        long long upper=lower*1000-1;
        if(upper>n)upper=n;
        long long cnt=upper-lower+1;
        ans+=cnt*cm;
        cm++;
        lower*=1000;
       }
       return ans;
    }
};