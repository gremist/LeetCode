// LeetCode 637 Average of Levels in Binary Tree.cpp

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
    vector<double> averageOfLevels(TreeNode* root) {
        if (!root) return {};
        vector<double> avg_vec;
        
        queue<TreeNode *> q;
        q.push(root);
        
        while (!q.empty()) {
            int n = q.size();
            long sum = 0;
            for (int i = 0; i < n; i++) {
                TreeNode *front = q.front();
                q.pop();
                sum += front->val;
                if (front->left) {
                    q.push(front->left);
                }
                if (front->right) {
                    q.push(front->right);
                }
            }
            avg_vec.push_back((double)sum / n);
        }
        return avg_vec;
    }
};