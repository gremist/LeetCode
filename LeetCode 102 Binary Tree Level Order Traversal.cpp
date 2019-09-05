// LeetCode 102 Binary Tree Level Order Traversal.cpp

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> ans;
        
        queue<TreeNode *> q;
        q.push(root);
        
        while (!q.empty()) {
            ans.emplace_back(q.size());
            for (int &val : ans.back()) {
                TreeNode *front = q.front();
                q.pop();
                val = front->val;
                if (front->left) {
                    q.push(front->left);
                }
                if (front->right) {
                    q.push(front->right);
                }
            }
        }
        return ans;
    }
};