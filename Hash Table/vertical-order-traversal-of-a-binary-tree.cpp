class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int, int>>> mp;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        
        while (!q.empty()) {
            auto f = q.front();
            q.pop();
            
            TreeNode* node = f.first;
            int x = f.second.first;
            int y = f.second.second;
            
            mp[x].push_back({y, node->val});
            
            if (node->left) {
                q.push({node->left, {x - 1, y + 1}});
            }
            if (node->right) {
                q.push({node->right, {x + 1, y + 1}});
            }
        }
        
        vector<vector<int>> ans;
        for (auto& it : mp) {
            auto& colList = it.second;
            sort(colList.begin(), colList.end());
            
            vector<int> temp;
            for (auto& p : colList) {
                temp.push_back(p.second);
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};