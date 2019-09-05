// LeetCode 83 Remove Duplicates from Sorted List.cpp

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *pi = head;
        while (pi && pi->next) {
            if (pi->val == pi->next->val) {
                ListNode *del = pi->next;
                pi->next = pi->next->next;
                delete del;
            } else {
                pi = pi->next;
            }
        }
        return head;
    }
};