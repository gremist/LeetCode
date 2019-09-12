// LeetCode 889 Construct Binary Tree from Preorder and Postorder Traversal.cpp

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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        return dfs(pre, post, 0, 0, pre.size());
    }
    
private:
    TreeNode * dfs(vector<int>& pre, vector<int>& post, int pri, int poi, int size) {
        if (size <= 0) return NULL;
        if (size == 1) return new TreeNode(pre[pri]);
        for (int i = 0; i < size - 1; i++) {
            if (post[poi + i] == pre[pri + 1]) {
                TreeNode *node = new TreeNode(pre[pri]);
                node->left  = dfs(pre, post, pri + 1, poi, i + 1);
                node->right = dfs(pre, post, pri + i + 2, poi + i + 1, size - i - 2);
                return node;
            }
        }
        throw logic_error("Unreachable code path");
    }
};