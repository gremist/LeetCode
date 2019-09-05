// LeetCode 111 Minimum Depth of Binary Tree.cpp

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 方法1：深度优先搜索
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        if (!root->left)  return minDepth(root->right) + 1;
        if (!root->right) return minDepth(root->left)  + 1;
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};

// 方法2：广度优先搜索
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        
        queue<TreeNode *> q;
        q.push(root);
        
        int depth = 1;
        while (!q.empty()) {
            for (int i = 0, n = q.size(); i < n; i++) {
                TreeNode *front = q.front();
                q.pop();
                if (!front->left && !front->right) {
                    return depth;
                }
                if (front->left) {
                    q.push(front->left);
                }
                if (front->right) {
                    q.push(front->right);
                }
            }
            depth++;
        }
        throw logic_error("Unreachable code path");
    }
};