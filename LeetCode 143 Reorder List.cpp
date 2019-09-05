// LeetCode 143 Reorder List.cpp

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
    void reorderList(ListNode* head) {
        ListNode *ps = head, *pf = head;
        while (pf && pf->next) {
            ps = ps->next;
            pf = pf->next->next;
        }
        
        ListNode *pb = NULL;
        while (ps) {
            ListNode *pt = ps->next;
            ps->next = pb;
            pb = ps;
            ps = pt;
        }
        
        ListNode *pa = head;
        while (pa) {
            ListNode *pt = pa->next;
            pa->next = pb;
            pa = pb;
            pb = pt;
        }
    }
};