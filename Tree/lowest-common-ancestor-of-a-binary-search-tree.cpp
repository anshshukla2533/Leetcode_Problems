class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case: if root is null or we found one of the targets
        if (!root || root == p || root == q) {
            return root;
        }
        
        // Search in left and right subtrees
        TreeNode* leftResult = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightResult = lowestCommonAncestor(root->right, p, q);
        
        // If both left and right return non-null, `p` and `q` are on separate sides; 
        // therefore, the current `root` is the Lowest Common Ancestor.
        if (leftResult && rightResult) {
            return root;
        }
        
        // Otherwise, return whichever side was non-null (or nullptr if neither found)
        return leftResult ? leftResult : rightResult;
    }
};