// LeetCode 203 Remove Linked List Elements.cpp

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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode fake(0);
        fake.next = head;
        
        ListNode *pi = &fake;
        while (pi->next) {
            if (pi->next->val == val) {
                ListNode *del = pi->next;
                pi->next = pi->next->next;
                delete del;
            } else {
                pi = pi->next;
            }
        }
        return fake.next;
    }
};