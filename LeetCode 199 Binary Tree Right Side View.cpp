// LeetCode 199 Binary Tree Right Side View.cpp

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        dfs(ans, root, 0);
        return ans;
    }
    
private:
    void dfs(vector<int> &ans, TreeNode *root, int depth) {
        if (!root) return;
        if (depth >= ans.size()) {
            ans.push_back(root->val);
        }
        dfs(ans, root->right, depth + 1);
        dfs(ans, root->left,  depth + 1);
    }
};