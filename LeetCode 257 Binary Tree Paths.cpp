// LeetCode 257 Binary Tree Paths.cpp

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        dfs(ans, "", root);
        return ans;
    }

private:
    void dfs(vector<string> &ans, string path, TreeNode *root) {
        if (!root) return;
        
        path += to_string(root->val);
        dfs(ans, path + "->", root->left);
        dfs(ans, path + "->", root->right);
        
        if (!root->left && !root->right) {
            ans.push_back(path);
        }
    }
};