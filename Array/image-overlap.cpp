class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int maxi=0;
        int n=img1.size();
        for(int x=-n+1;x<n;x++){
            for(int y=-n+1;y<n;y++){
                int cnt=0;
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        int dx=x+i;
                        int dy=y+j;
                        if(dx>=0 && dx<n && dy>=0 && dy<n){
                            if(img1[dx][dy]==1 &&  img2[i][j])cnt++;
                        }
                    }
                }
                maxi=max(maxi,cnt);
            }
        }
        return maxi;
    }
};