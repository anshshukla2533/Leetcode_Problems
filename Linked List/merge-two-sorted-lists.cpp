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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;
       ListNode* temp1=list1;
       ListNode* temp2=list2;
       ListNode* temphead;
       ListNode* head;
       if(temp1->val>=temp2->val){
        head=temp2;
        temp2=temp2->next;
       }else{
        head=temp1;
        temp1=temp1->next;
       }
       temphead=head;
       while(temp1 && temp2){
          if(temp1->val>=temp2->val){
            temphead->next=temp2;
            temp2=temp2->next;
            
          }else{
            temphead->next=temp1;
            temp1=temp1->next;
          }
          temphead=temphead->next;
       }
       while(temp1){
        temphead->next=temp1;
        temp1=temp1->next;
         temphead=temphead->next;
       }
       while(temp2){
        temphead->next=temp2;
        temp2=temp2->next;
         temphead=temphead->next;
       }
       return head;
    }
};