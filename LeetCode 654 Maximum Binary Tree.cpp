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
        return construct(nums, 0, nums.size());
    }
    
private:
    TreeNode * construct(vector<int> &nums, int begin, int end) {
        if (begin >= end) return NULL;
        int cut = begin;
        for (int i = begin + 1; i < end; i++) {
            if (nums[i] > nums[cut]) {
                cut = i;
            }
        }
        TreeNode *root = new TreeNode(nums[cut]);
        root->left  = construct(nums, begin, cut);
        root->right = construct(nums, cut + 1, end);
        return root;
    }
};