// LeetCode 987 Vertical Order Traversal of a Binary Tree.cpp

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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> locs;
        dfs(locs, root, 0, 0);
        sort(locs.begin(), locs.end(), [] (vector<int> &a, vector<int> &b) {
            if (a[0] != b[0]) return a[0] < b[0];
            if (a[1] != b[1]) return a[1] < b[1];
            return a[2] < b[2];
        });
        
        vector<vector<int>> ans;
        for (int i = 0; i < locs.size(); i++) {
            if (i == 0 || locs[i - 1][0] < locs[i][0]) {
                ans.emplace_back();
            }
            ans.back().push_back(locs[i][2]);
        }
        return ans;
    }
    
private:
    void dfs(vector<vector<int>> &locs, TreeNode *root, int x, int y) {
        if (!root) return;
        locs.push_back({x, y, root->val});
        dfs(locs, root->left, x - 1, y + 1);
        dfs(locs, root->right, x + 1, y + 1);
    }
};