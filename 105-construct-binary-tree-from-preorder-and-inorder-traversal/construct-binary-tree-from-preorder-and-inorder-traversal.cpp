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
private:
    unordered_map<int, int> inorderMap;

    TreeNode* build(vector<int>& preorder, int preStart, int preEnd, int inStart, int inEnd) {
       if (preStart > preEnd || inStart > inEnd) return nullptr;

        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);

        // Find the position of the root in the inorder array
        int inIndex = inorderMap[rootVal];
        int leftSize = inIndex - inStart;

        // Recursively build the left and right subtrees
        root->left = build(preorder, preStart + 1, preStart + leftSize, inStart, inIndex - 1);
        root->right = build(preorder, preStart + leftSize + 1, preEnd, inIndex + 1, inEnd);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Map inorder values to their indices for O(1) lookup
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }

        return build(preorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};