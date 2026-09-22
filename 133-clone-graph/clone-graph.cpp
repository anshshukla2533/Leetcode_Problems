class Solution {
public:
    unordered_map<Node*, Node*> mp;

    void dfs(Node* current, Node* cloned) {
        for (auto it : current->neighbors) {
            if (mp.find(it) == mp.end()) {
                Node* cloneNode = new Node(it->val);
                mp[it] = cloneNode;
                cloned->neighbors.push_back(cloneNode);
                dfs(it, cloneNode);
            } else {
                cloned->neighbors.push_back(mp[it]);
            }
        }
    }
     void bfs(queue<Node*>& q) {
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            Node* clone = mp[curr];

            for (Node* nei : curr->neighbors) {
                if (mp.find(nei) == mp.end()) {
                    mp[nei] = new Node(nei->val);
                    q.push(nei);    
                }
                clone->neighbors.push_back(mp[nei]);
            }
        }
    }


    Node* cloneGraph(Node* node) {
        if (!node) return NULL;
        
        Node* cloned = new Node(node->val);
        mp[node] = cloned;
        //dfs(node, cloned);
         queue<Node*>q;
         q.push(node);
         bfs(q);
        
        return cloned;
    }
};