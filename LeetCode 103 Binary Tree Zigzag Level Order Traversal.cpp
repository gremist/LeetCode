// LeetCode 103 Binary Tree Zigzag Level Order Traversal.cpp

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> ans;
        
        queue<TreeNode *> q;
        q.push(root);
        
        while (!q.empty()) {
            ans.emplace_back(q.size());
            for (int i = 0, n = q.size(); i < n; i++) {
                TreeNode *front = q.front();
                q.pop();
                ans.back()[ans.size() % 2 ? i : n - i - 1] = front->val;
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