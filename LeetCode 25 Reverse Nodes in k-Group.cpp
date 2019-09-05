// LeetCode 25 Reverse Nodes in k-Group.cpp

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *pa = head;
        for (int i = 0; i < k; i++) {
            if (!pa) {
                return head;
            }
            pa = pa->next;
        }

        ListNode *pb = reverseKGroup(pa, k);
        while (head != pa) {
            ListNode *pc = head->next;
            head->next = pb;
            pb = head;
            head = pc;
        }
        return pb;
    }
};