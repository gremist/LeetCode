// LeetCode 337 House Robber III.cpp

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
    int rob(TreeNode* root) {
        vector<int> v = dfs(root);
        return max(v[0], v[1]);
    }
    
private:
    vector<int> dfs(TreeNode *root) {
        if (!root) return {0, 0};
        vector<int> vl = dfs(root->left);
        vector<int> vr = dfs(root->right);
        return {root->val + vl[1] + vr[1], 
            max(vl[0], vl[1]) + max(vr[0], vr[1])};
    }
};