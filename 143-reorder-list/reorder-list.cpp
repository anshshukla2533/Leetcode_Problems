class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
      
        ListNode* prev=NULL;
        ListNode* curr=slow->next;
          slow->next = nullptr;
        while(curr){
            ListNode* nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        ListNode* first=head;
        ListNode* second=prev;
        while(second){
            ListNode* temp1=first->next;
            ListNode* temp2=second->next;
            first->next=second;
            second->next=temp1;

            first=temp1;
            second=temp2;
        }
      //  return head;

    }
};