// LeetCode 234 Palindrome Linked List.cpp

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
    bool isPalindrome(ListNode* head) {
        ListNode *ps = head, *pf = head;
        while (pf && pf->next) {
            ps = ps->next;
            pf = pf->next->next;
        }
        
        ListNode *rhead = NULL;
        while (ps) {
            ListNode *pt = ps->next;
            ps->next = rhead;
            rhead = ps;
            ps = pt;
        }
        
        bool ans = true;
        ListNode *pa = head, *pb = rhead;
        while (pb) {
            if (pa->val != pb->val) {
                ans = false;
            }
            ListNode *pt = pb->next;
            pb->next = ps;
            ps = pb;
            pb = pt;
            pa = pa->next;
        }
        return ans;
    }
};