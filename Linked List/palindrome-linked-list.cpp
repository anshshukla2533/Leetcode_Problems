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
    bool isPalindrome(ListNode* head) {
        vector<ListNode*>node;
        while(head){
            node.push_back(head);
            head=head->next;
        }
        int i=0;
        int j=node.size()-1;
        while(i<j){
            if(node[i]->val != node[j]->val)return false;
            i++;
            j--;

        }
        return true;


    }
};