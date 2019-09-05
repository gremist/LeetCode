// LeetCode 606 Construct String from Binary Tree.cpp

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
    string tree2str(TreeNode* t) {
        if (!t) return "";
        string ans = to_string(t->val);
        if (!t->left && !t->right) {
            return ans;
        }
        ans += "(" + tree2str(t->left) + ")";
        if (!t->right) {
            return ans;
        }
        return ans + "(" + tree2str(t->right) + ")";
    }
};