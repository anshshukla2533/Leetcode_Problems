class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if (!root) return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
             int i=0;
             vector<int>temp;
            for(int i=0;i<sz;i++){
                TreeNode* nd=q.front();
                q.pop();
                temp.push_back(nd->val);
                if(nd->left){
                    q.push(nd->left);
                }
                if(nd->right)q.push(nd->right);
            }
            ans.push_back(temp.back());
        }

        return ans;
    }
};
