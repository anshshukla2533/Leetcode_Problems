class Solution {
public:
    int cnt = 0;

    pair<int, int> dfs(TreeNode* root) {
        if (root == NULL) return {0, 0};

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        int currentsum = root->val + left.first + right.first;
        int cntnodes = 1 + left.second + right.second;

        if (currentsum / cntnodes == root->val) {
            cnt++;
        }

        return {currentsum, cntnodes};
    }

    int averageOfSubtree(TreeNode* root) {
        cnt = 0;
        dfs(root);
        return cnt;
    }
};