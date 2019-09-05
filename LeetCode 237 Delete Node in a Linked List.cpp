// LeetCode 237 Delete Node in a Linked List.cpp

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
    void deleteNode(ListNode* node) {
        ListNode* del = node->next;
        node->val  = del->val;
        node->next = del->next;
        delete del;
    }
};