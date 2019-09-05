// LeetCode 92 Reverse Linked List II.cpp

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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode fake(0);
        fake.next = head;
        
        ListNode *pa = &fake;
        for (int i = 1; i < m; i++) {
            pa = pa->next;
        }
        
        head = pa->next;
        for (int i = m; i < n; i++) {
            ListNode *pb = head->next;
            head->next = pb->next;
            pb->next = pa->next;
            pa->next = pb;
        }
        return fake.next;
    }
};