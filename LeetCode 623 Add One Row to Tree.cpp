// LeetCode 623 Add One Row to Tree.cpp

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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (!root) return NULL;
        if (d == 1) {
            TreeNode *node = new TreeNode(v);
            node->left = root;
            root = node;
        } else if (d == 2) {
            TreeNode *node = new TreeNode(v);
            node->left = root->left;
            root->left = node;
            node = new TreeNode(v);
            node->right = root->right;
            root->right = node;
        } else {
            addOneRow(root->left , v, d - 1);
            addOneRow(root->right, v, d - 1);
        }
        return root;
    }
};