// LeetCode 106 Construct Binary Tree from Inorder and Postorder Traversal.cpp

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return dfs(inorder, postorder, 0, 0, inorder.size());
    }
    
private: 
    TreeNode * dfs(vector<int>& inorder, vector<int>& postorder, int ii, int pi, int size) {
        if (size <= 0) return NULL;
        for (int i = 0; i < size; i++) {
            if (inorder[ii + i] == postorder[pi + size - 1]) {
                TreeNode *root = new TreeNode(postorder[pi + size - 1]); 
                root->left  = dfs(inorder, postorder, ii, pi, i);
                root->right = dfs(inorder, postorder, ii + i + 1, pi + i, size - i - 1);
                return root;
            }
        }
        throw logic_error("Unreachable code path");
    }
};