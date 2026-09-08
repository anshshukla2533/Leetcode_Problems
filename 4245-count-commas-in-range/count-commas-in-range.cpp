class Solution {
public:
    int countCommas(int n) {
        // brute force
        /*
        if(n<1000)return 0;
        if(n==100000)return 99001;
        int ans=0;
        for(int i=1000;i<=n;i++){
           string num=to_string(i);
           ans+=num.size()/3;
           }
           return ans;

        }
        */
        if(n<1000)return 0;
        return n-999;
        
    }
        
    
};