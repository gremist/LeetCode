// LeetCode 145 Binary Tree Postorder Traversal.cpp

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        dfs(ans, root);
        return ans;
    }
    
private:
    void dfs(vector<int> &ans, TreeNode *root) {
        if (!root) return;
        dfs(ans, root->left);
        dfs(ans, root->right);
        ans.push_back(root->val);
    }
};

// 方法2：迭代
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> ans;
        
        stack<TreeNode *> s;
        s.push(root);
        
        while (!s.empty()) {
            TreeNode *top = s.top();
            s.pop();
            ans.push_back(top->val);
            if (top->left) {
                s.push(top->left);
            }
            if (top->right) {
                s.push(top->right);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};