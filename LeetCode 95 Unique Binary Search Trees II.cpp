// LeetCode 95 Unique Binary Search Trees II.cpp

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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return generate(1, n + 1);
    }
    
private:
    vector<TreeNode *> generate(int begin, int end) {
        if (begin >= end) return {NULL};
        vector<TreeNode *> ans;
        for (int i = begin; i < end; i++) {
            vector<TreeNode *> vl = generate(begin, i);
            vector<TreeNode *> vr = generate(i + 1, end);
            for (TreeNode *l : vl) {
                for (TreeNode *r : vr) {
                    ans.push_back(new TreeNode(i));
                    ans.back()->left  = l;
                    ans.back()->right = r;
                }
            }
        }
        return ans;
    }
};