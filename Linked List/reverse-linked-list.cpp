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
    ListNode* reverseList(ListNode* head) {
        /*
        vector<int>arr;
        ListNode* temp=head;
        while(temp){
            arr.push_back(temp->val);
            temp=temp->next;
        }
        ListNode* temp2=head;
        int i=arr.size()-1;
        
        while(temp2 && i>=0){
            temp2->val=arr[i];
            temp2=temp2->next;
            i--;
        }
        return head;
        */
        ListNode* cur=head;
        ListNode* prev=NULL;
        while(cur){
            ListNode* next=cur->next;
            cur->next = prev;
    
            prev=cur;
            cur=next;
        }
        return prev;
    }
};