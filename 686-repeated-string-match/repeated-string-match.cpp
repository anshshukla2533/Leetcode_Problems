class Solution {
public:
    bool find(string a,string b){
        int n=a.length();
        int m=b.size();
        if(m>n)return false;
        for(int i=0;i<=n-m;i++){
            int j=0;
            while(j<m && a[i+j]==b[j]){
                j++;
            }
            if(j==m)return true;
        }
        return false;
    }
    int repeatedStringMatch(string a, string b) {
       string temp=a;
       int cnt=1;
       while(temp.length()<b.length()){
        temp+=a;
        cnt++;
       }
       if(find(temp,b)){
        return cnt;
       }
       temp+=a;
       if(find(temp,b)){
        return cnt+1;
       }
       return -1;
    }
};