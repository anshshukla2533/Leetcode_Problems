class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        
        vector<ListNode*> temp;
        ListNode* h = head;
        while(h) {
            temp.push_back(h);
            h = h->next;
        }
        
        int n = temp.size();
        int i = 1;      // Start from 1 because temp[0] is already the head
        int j = n - 1;
        
        ListNode* curr = head;
        
        while(i <= j) {
            curr->next = temp[j];
            curr = curr->next;
            j--;
            
            if (i > j) break;
            
            curr->next = temp[i];
            curr = curr->next;
            i++;
        }
        
        // Terminate the list properly
        curr->next = nullptr;
    }
};