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
    vector<TreeNode*>temp;
    void inorder(TreeNode* root){
        if(root==NULL)return ;
        inorder(root->left);
        temp.push_back(root);
        inorder(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        if(!root)return NULL;
      inorder(root);
      return temp[k-1]->val;
    }
};