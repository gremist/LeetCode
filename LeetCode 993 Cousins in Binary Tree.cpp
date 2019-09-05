// LeetCode 993 Cousins in Binary Tree.cpp

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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int li = -1;
            for (int i = 0, n = q.size(); i < n; i++) {
                TreeNode *front = q.front();
                q.pop();
                if (!front) {
                    continue;
                }
                if (front->val == x || front->val == y) {
                    if (li == -1) {
                        li = i;
                    } else {
                        return i > li + 1 || li % 2;
                    }
                }
                q.push(front->left);
                q.push(front->right);
            }
            if (li != -1) {
                return false;
            }
        }
        throw logic_error("Unreachable code path");
    }
};