// LeetCode 589 N-ary Tree Preorder Traversal.cpp

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
    vector<int> preorder(Node* root) {
        vector<int> ans;
        dfs(ans, root);
        return ans;
    }
    
private:
    void dfs(vector<int> &ans, Node *root) {
        if (!root) return;
        ans.push_back(root->val);
        for (Node *c : root->children) {
            dfs(ans, c);
        }
    }
};