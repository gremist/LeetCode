// LeetCode 437 Path Sum III.cpp

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
    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        return sameRootPathSum(root, sum) +
            pathSum(root->left, sum) +
            pathSum(root->right, sum);
    }

private:
    int sameRootPathSum(TreeNode *root, int sum) {
        if (!root) return 0;
        return (root->val == sum ? 1 : 0) +
            sameRootPathSum(root->left, sum - root->val) +
            sameRootPathSum(root->right, sum - root->val);
    }
};