class Solution {
public:
     int t[1001][1501];
     int solve(int idx,vector<vector<int>>&items,int budget,int mp,vector<int>&cp){
        if(idx<0){
            return budget/mp;
        }
        if(t[idx][budget]!=-1)return t[idx][budget];
        int take=0;
       
        if(items[idx][1]<=budget){
            take=1+cp[idx]+solve(idx-1,items,budget-items[idx][1],mp,cp);
        }
       int skip=solve(idx-1,items,budget,mp,cp);
        return t[idx][budget]=max(take,skip);
     }
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n=items.size();
        vector<int>cp(n,0);
        int mp=INT_MAX;
        memset(t,-1,sizeof(t));

        for(int i=0;i<n;i++){
            int copy=0;
            mp = min(mp, items[i][1]);
            for(int j=0;j<n;j++){
               if (i != j && items[j][0] % items[i][0] == 0) {
                    copy++;
                }
            }
            cp[i]=copy;
        }
        return solve(n-1,items,budget,mp,cp);
    }
};