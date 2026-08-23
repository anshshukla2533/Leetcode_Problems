class Solution {
public:
    bool sumGame(string num) {
        int q1=0;
        int q2=0;
        int n=num.size();
        int s1=0;
        int s2=0;
        for(int  i=0;i<n;i++){
            if(num[i]=='?' && i<n/2){
                q1++;
                
            }
            else if(num[i]!='?' && i<n/2){
                s1+=(num[i]-'0');
            }
            else if(num[i]=='?' && i>=n/2){
                q2++;
            }
            else if(num[i]!='?' && i>=n/2){
                s2+=(num[i]-'0');
            }

        }
        if((q1+q2)&1)return true;
        bool bob (2 * (s1 - s2) == 9 * (q2 - q1));
        if(bob)return false;
        return true;

    }
};