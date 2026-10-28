/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
   void dfs(TreeNode* root,int maxi,int &ans){
    if(root==NULL)return;
    if(root->val>=maxi){
        maxi=root->val;
      ans++;
    }
    dfs(root->left,maxi,ans);
    dfs(root->right,maxi,ans);

   }
    
    int goodNodes(TreeNode* root) {
        int ans=0;
        if (root == NULL) return 0;
        int maxi=root->val;
    
        dfs(root,maxi,ans);
        return ans;
        
    }
};