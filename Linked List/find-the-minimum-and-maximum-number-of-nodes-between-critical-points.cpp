/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next) return {-1, -1};
        vector<int>ans;
        ListNode* prev=head;
        ListNode* cur=head->next;
        ListNode* ahead=cur->next;
        int i=1;
        
        while(ahead){
        if ((prev->val > cur->val && cur->val < ahead->val) || 
         (cur->val > prev->val && cur->val > ahead->val)) {
         ans.push_back(i);
          }
            prev = cur;
            cur = ahead;
            ahead = ahead->next;
            i++;

        }
        if(ans.size()<2)return {-1,-1};
        int mini = INT_MAX;
        int maxi = ans.back() - ans.front();

        for (int i = 1; i < ans.size(); i++) {
           mini = min(mini, ans[i] - ans[i - 1]);
        }

      return {mini, maxi};

    }
};