/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*,Node*>mp;
    Node* cloneGraph(Node* node) {
        if (!node) return NULL;
        Node* head=new Node(node->val);
        mp[node]=head;
        for (auto i:node->neighbors){
            if (mp.count(i)) head->neighbors.push_back(mp[i]);
            else
                head->neighbors.push_back(cloneGraph(i));
        }
        return head;
    }
};