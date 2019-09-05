// LeetCode 94 Binary Tree Inorder Traversal.cpp

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 方法1：递归
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        dfs(ans, root);
        return ans;
    }
    
private:
    void dfs(vector<int> &ans, TreeNode *root) {
        if (!root) return;
        dfs(ans, root->left);
        ans.push_back(root->val);
        dfs(ans, root->right);
    }
};

// 方法2：迭代
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode *> s;
        while (root || !s.empty()) {
            while (root) {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            ans.push_back(root->val);
            root = root->right;
        }
        return ans;
    }
};