class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> temp;
        ListNode* t = head;
        while (t != nullptr) {
            temp.push_back(t);
            t = t->next;
        }
        
        int sz = temp.size();
        int targetIdx = sz - n;
        if (targetIdx == 0) {
            return head->next;
        }
        temp[targetIdx - 1]->next = temp[targetIdx]->next;
        
        return head;
    }
};