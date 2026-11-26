class Solution {
public:
    bool canAliceWin(int n) {
        int take=10;
        int st=0;
        while(n>=take){
            n-=take;
            take--;
            st++;
        }
        return st%2!=0;
    }
};