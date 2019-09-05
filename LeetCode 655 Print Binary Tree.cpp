// LeetCode 655 Print Binary Tree.cpp

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
    vector<vector<string>> printTree(TreeNode* root) {
        int m = maxDepth(root);
        int n = (1 << m) - 1;
        vector<vector<string>> ans(m, vector<string>(n));
        dfs(ans, root, 0, n, 0);
        return ans;
    }
    
private:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
    
    void dfs(vector<vector<string>> &ans, TreeNode *root, int begin, int end, int row) {
        if (!root) return;
        int col = (begin + end) / 2;
        ans[row][col] = to_string(root->val);
        dfs(ans, root->left, begin, col, row + 1);
        dfs(ans, root->right, col, end, row + 1);
    }
};