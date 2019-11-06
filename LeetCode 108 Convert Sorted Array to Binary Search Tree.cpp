// LeetCode 108 Convert Sorted Array to Binary Search Tree.cpp

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(nums, 0, nums.size());
    }
    
private:
    TreeNode * dfs(vector<int> &nums, int begin, int end) {
        if (begin >= end) return NULL;
        int cut = (begin + end) / 2;
        TreeNode *root = new TreeNode(nums[cut]);
        root->left  = dfs(nums, begin, cut);
        root->right = dfs(nums, cut + 1, end);
        return root;
    }
};