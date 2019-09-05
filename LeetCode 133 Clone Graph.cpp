// LeetCode 133 Clone Graph.cpp

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node *, Node *> m;
        return dfs(m, node);
    }
    
private:
    Node * dfs(unordered_map<Node *, Node *> &m, Node *node) {
        if (!node) return NULL;
        if (m.find(node) != m.end()) return m[node];
            
        Node *clone = new Node(node->val);
        m[node] = clone;
        
        for (Node *neighbor : node->neighbors) {
            clone->neighbors.push_back(dfs(m, neighbor));
        }
        return clone;
    }
};