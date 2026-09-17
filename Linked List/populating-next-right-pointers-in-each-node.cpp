/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)return NULL;
        queue<Node*>q;
        q.push(root);
        root->next=NULL;
        while(!q.empty()){
            int s=q.size();
            vector<Node*>temp;
            while(s--){
                auto n=q.front();
                q.pop();
            
                if(n->left){
                    q.push(n->left);
                    temp.push_back(n->left);
                }
                if(n->right){
                    q.push(n->right);
                    temp.push_back(n->right);
                }
            }
            if (!temp.empty()) {
             for (int i = 0; i < temp.size() - 1; i++) {
               temp[i]->next = temp[i + 1];
              }
         temp.back()->next = NULL;
         }
        }
        return root;
    }
};