// LeetCode 110 Balanced Binary Tree.cpp

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
    bool isBalanced(TreeNode* root) {
        return dfs(root) > -1;
    }
    
private:
    int dfs(TreeNode *root) {
        if (!root) return 0;
        
        int ld = dfs(root->left);
        if (ld < 0) {
            return -1;
        }
        
        int rd = dfs(root->right);
        if (rd < 0 || abs(ld - rd) > 1) {
            return -1;
        }
        return max(ld, rd) + 1;
    }
};