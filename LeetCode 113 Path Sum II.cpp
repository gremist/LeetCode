// LeetCode 113 Path Sum II.cpp

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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        vector<int> cur;
        dfs(ans, cur, root, sum);
        return ans;
    }
    
public:
    void dfs(vector<vector<int>> &ans, vector<int> &cur, TreeNode *root, int sum) {
        if (!root) return;
        cur.push_back(root->val);
        if (!root->left && !root->right && root->val == sum) {
            ans.push_back(cur);
        }
        dfs(ans, cur, root->left, sum - root->val);
        dfs(ans, cur, root->right, sum - root->val);
        cur.pop_back();
    }
};