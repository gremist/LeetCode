// LeetCode 590 N-ary Tree Postorder Traversal.cpp

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
    vector<int> postorder(Node* root) {
        vector<int> ans;
        dfs(ans, root);
        return ans;
    }
    
private:
    void dfs(vector<int> &ans, Node *root) {
        if (!root) return;
        for (Node *c : root->children) {
            dfs(ans, c);
        }
        ans.push_back(root->val);
    }
};