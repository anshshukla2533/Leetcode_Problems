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
    ListNode* rotateRight(ListNode* head, int k) {
        vector<int>arr;
        ListNode* temp=head;
        while(temp){
            arr.push_back(temp->val);
            temp=temp->next;
        }
        vector<int>rotate(arr.size(),0);
        int n=arr.size();
        for(int i=0;i<n;i++){
            rotate[(k+i)%n]=arr[i];
        }
        
        ListNode* dummy=new ListNode(-1);
        ListNode* head1=dummy;
        for(int i=0;i<n;i++){
            dummy->next=new ListNode(rotate[i]);
            dummy=dummy->next;
        }
        return head1->next;
    }
};