class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {

        int cnt1=0;
        for(auto it:s){
            if(it=='1')cnt1++;
        }
        s = "1" + s + "1";
        int maxgain=cnt1;
        int n=s.size();
        int i=0;
        while( i<n && s[i]=='1' ){
            i++;
        }
        //firs 0-block;
        int left=0;
            while( i<n && s[i]=='0'){
                left++;
                i++;
            }
        
        while(i<n){
            
            int mid=0;
            while(i<n && s[i]=='1'){
                mid++;
                i++;
            }
            if(mid==0)break;
            
            
            int right=0;
            while(i<n &&s[i]=='0'){
                right++;
                i++;
            }
            if(right==0)break;
            maxgain=max(maxgain,cnt1+left+right);
            left=right;
        }
        return maxgain;
        
    }
};