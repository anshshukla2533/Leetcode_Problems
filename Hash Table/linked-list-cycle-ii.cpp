/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*>node;
        ListNode* temp=head;
        while(temp){
            if(node.count(temp))return temp;
            node.insert(temp);
            
            temp=temp->next;
        }
        return NULL;

       
    }
};