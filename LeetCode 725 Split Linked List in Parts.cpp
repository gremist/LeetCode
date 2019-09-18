// LeetCode 725 Split Linked List in Parts.cpp

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int size = 0;
        ListNode *pi = root;
        while (pi) {
            size++;
            pi = pi->next;
        }
        
        vector<ListNode *> ans(k);
        for (int i = 0; i < k; i++) {
            if (!root) break;
            ans[i] = pi = root;
            for (int j = 0; j < size / k - (i < size % k ? 0 : 1); j++) {
                pi = pi->next;
            }
            root = pi->next;
            pi->next = NULL;
        }
        return ans;
    }
};