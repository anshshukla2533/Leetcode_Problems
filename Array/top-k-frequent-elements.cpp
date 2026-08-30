class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (auto num : nums) {
            mp[num]++;
        }

   
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minhp;

        for (auto& it : mp) {
            minhp.push({it.second, it.first});
            if (minhp.size() > k) {
                minhp.pop();
            }
        }

        vector<int> ans;
        while (!minhp.empty()) {
            ans.push_back(minhp.top().second);
            minhp.pop();
        }

        return ans;
    }
};