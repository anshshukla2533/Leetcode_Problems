class Solution {
public:
   pair<int,int> sumoproduct(int n){
    int s=0;
    int p=1;
    while(n){
        int digit=n%10;
        s+=digit;
        p*=digit;
        n/=10;
    }
    return {s,p};
   }

    bool checkDivisibility(int n) {
        
    auto [sum, product]=sumoproduct(n);
    if(n%(sum+product)==0)return true;
    return false;
    }
};