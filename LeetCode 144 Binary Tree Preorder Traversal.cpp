// LeetCode 144 Binary Tree Preorder Traversal.cpp

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        dfs(ans, root);
        return ans;
    }

private:
    void dfs(vector<int> &ans, TreeNode *root) {
        if (!root) return;
        ans.push_back(root->val);
        dfs(ans, root->left);
        dfs(ans, root->right);
    }
};

// 方法2：迭代
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> ans;
        
        stack<TreeNode *> s;
        s.push(root);
        
        while (!s.empty()) {
            TreeNode *top = s.top();
            s.pop();
            ans.push_back(top->val);
            if (top->right) {
                s.push(top->right);
            }
            if (top->left) {
                s.push(top->left);
            }
        }
        return ans;
    }
};