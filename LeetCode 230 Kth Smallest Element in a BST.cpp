// LeetCode 230 Kth Smallest Element in a BST.cpp

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
    int kthSmallest(TreeNode* root, int k) {
        return dfs(root, k)->val;
    }
    
    TreeNode * dfs(TreeNode *root, int &k) {
        if (!root) return NULL;
        TreeNode *left = dfs(root->left, k);
        if (left) {
            return left;
        }
        if (!--k) {
            return root;
        }
        return dfs(root->right, k);
    }
};