// LeetCode 109 Convert Sorted List to Binary Search Tree.cpp

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return NULL;
        if (!head->next) return new TreeNode(head->val);
        
        ListNode *pi, *ps = head, *pf = head;
        while (pf && pf->next) {
            pi = ps;
            ps = ps->next;
            pf = pf->next->next;
        }
        
        pi->next = NULL;
        TreeNode *root = new TreeNode(ps->val);
        root->left  = sortedListToBST(head);
        root->right = sortedListToBST(ps->next);
        pi->next = ps;
        return root;
    }
};