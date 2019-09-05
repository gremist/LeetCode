// LeetCode 563 Binary Tree Tilt.cpp

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
    int findTilt(TreeNode* root) {
        int ans = 0;
        dfs(ans, root);
        return ans;
    }
    
private:
    int dfs(int &ans, TreeNode *root) {
        if (!root) return 0;
        int l = dfs(ans, root->left);
        int r = dfs(ans, root->right);
        ans += abs(l - r);
        return l + r + root->val;
    }
};