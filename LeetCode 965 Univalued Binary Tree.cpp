// LeetCode 965 Univalued Binary Tree.cpp

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
    bool isUnivalTree(TreeNode* root) {
        if (!root->left && !root->right) return true;
        bool ans = true;
        if (root->left) {
            ans &= isUnivalTree(root->left);
            ans &= root->val == root->left->val;
        }
        if (root->right) {
            ans &= isUnivalTree(root->right);
            ans &= root->val == root->right->val;
        }
        return ans;
    }
};