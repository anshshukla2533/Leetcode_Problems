class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        unordered_map<Node*, Node*> clonedMap;
        clonedMap[node] = new Node(node->val);
        
        queue<Node*> q;
        q.push(node);
        
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            
            for (Node* neighbor : curr->neighbors) {
                if (clonedMap.find(neighbor) == clonedMap.end()) {
                    clonedMap[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
            
                clonedMap[curr]->neighbors.push_back(clonedMap[neighbor]);
            }
        }
        
        return clonedMap[node];
    }
};