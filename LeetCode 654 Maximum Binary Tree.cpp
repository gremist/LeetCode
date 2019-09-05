// LeetCode 654 Maximum Binary Tree.cpp

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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return construct(nums.begin(), nums.end());
    }
    
private:
    TreeNode * construct(vector<int>::iterator begin, vector<int>::iterator end) {
        if (begin == end) return NULL;
        auto it = max_element(begin, end);
        TreeNode *node = new TreeNode(*it);
        node->left  = construct(begin, it);
        node->right = construct(it + 1, end);
        return node;
    }
};