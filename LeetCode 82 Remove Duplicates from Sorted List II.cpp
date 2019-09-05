// LeetCode 82 Remove Duplicates from Sorted List II.cpp

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
        ListNode fake(0);
        fake.next = head;
        
        ListNode *pi = &fake;
        while (pi->next && pi->next->next) {
            if (pi->next->val == pi->next->next->val) {
                int val = pi->next->val;
                while (pi->next && pi->next->val == val) {
                    ListNode *del = pi->next;
                    pi->next = pi->next->next;
                    delete del;
                }
            } else {
                pi = pi->next;
            }
        }
        return fake.next;
    }
};