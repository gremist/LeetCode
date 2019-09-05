// LeetCode 429 N-ary Tree Level Order Traversal.cpp

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) return {};
        vector<vector<int>> ans;
        
        queue<Node *> q;
        q.push(root);
        
        while (!q.empty()) {
            ans.emplace_back(q.size());
            for (int &val : ans.back()) {
                Node *front = q.front();
                q.pop();
                val = front->val;
                for (Node *c : front->children) {
                    if (c) {
                        q.push(c);
                    }
                }
            }
        }
        return ans;
    }
};