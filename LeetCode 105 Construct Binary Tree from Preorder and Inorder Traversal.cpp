// LeetCode 105 Construct Binary Tree from Preorder and Inorder Traversal.cpp

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return dfs(preorder, inorder, 0, 0, preorder.size());
    }
    
private:
    TreeNode * dfs(vector<int> preorder, vector<int> &inorder, int pi, int ii, int size) {
        if (size <= 0) return NULL;
        for (int i = 0; i < size; i++) {
            if (inorder[ii + i] == preorder[pi]) {
                TreeNode *node = new TreeNode(preorder[pi]);
                node->left  = dfs(preorder, inorder, pi + 1, ii, i);
                node->right = dfs(preorder, inorder, pi + i + 1, ii + i + 1, size - i - 1);
                return node;
            }
        }
        throw logic_error("Unreachable code path");
    }
};