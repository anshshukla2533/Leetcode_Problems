class Solution {
public:
     
    int widthOfBinaryTree(TreeNode* root) {
   
        long long maxi=LLONG_MIN;
        queue<pair<TreeNode*,long long >>q;
        q.push({root,0});
        while(!q.empty()){
            long long first=0;
            long long last=0;
            long long s=q.size();
            long long m=s;
            long long minidx=q.front().second;
            long long x=0;
            while(s--){
                auto [n,i]=q.front();
                q.pop();
               
                long long  idx=i-minidx;
                if(x==0)first=idx;
                if(x==m-1)last=idx;
                if(n->left){
                  q.push({n->left,idx*2+1});
                  
                }
                if(n->right){
                    q.push({n->right,idx*2+2});
                }
                x++;

            }
            maxi=max(maxi,last-first+1);
        }
        return maxi;

        
    }
};
