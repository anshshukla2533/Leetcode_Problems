class Solution {
public:
    double myPow(double x, int n) {
     double ans=1.0;
      long long p = n;

        if (p < 0) {
            x = 1 / x;
            p = -p;
        }
     while(p){
        if(p&1){
            ans*=x;
            p--;
        }else{
            p/=2;
            x*=x;
        }
     }
     return ans;
    }
};