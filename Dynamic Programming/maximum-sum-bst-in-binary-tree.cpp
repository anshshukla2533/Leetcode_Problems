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
    struct NodeInfo {
        bool isBST;
        int minVal;
        int maxVal;
        int sum;
    };

    int maxSum = 0;

    NodeInfo traverse(TreeNode* root) {
        // Base case: Empty subtree is a valid BST
        if (!root) {
            return {true, INT_MAX, INT_MIN, 0};
        }

        // Post-order traversal: Process left and right subtrees first
        NodeInfo left = traverse(root->left);
        NodeInfo right = traverse(root->right);

        // Check if current tree rooted at `root` is a valid BST
        if (left.isBST && right.isBST && root->val > left.maxVal && root->val < right.minVal) {
            int currentSum = root->val + left.sum + right.sum;
            maxSum = max(maxSum, currentSum);

            return {
                true,
                min(root->val, left.minVal),
                max(root->val, right.maxVal),
                currentSum
            };
        }

        // Not a BST
        return {false, 0, 0, 0};
    }

public:
    int maxSumBST(TreeNode* root) {
        maxSum = 0;
        traverse(root);
        return maxSum;
    }
};