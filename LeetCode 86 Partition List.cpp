// LeetCode 86 Partition List.cpp

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 方法1：迭代
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode fake1(0), fake2(0);
        fake1.next = head;
        
        ListNode *pi = &fake1, *pj = &fake2;
        while (head) {
            if (head->val < x) {
                pi->next = head;
                pi = head;
            } else {
                pj->next = head;
                pj = head;
            }
            head = head->next;
        }
        pi->next = fake2.next;
        pj->next = NULL;
        return fake1.next;
    }
};

// 方法2：迭代
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode fake1(0), fake2(0);
        fake1.next = head;
        
        ListNode *pi = &fake1, *pj = &fake2;
        while (pi->next) {
            if (pi->next->val < x) {
                pi = pi->next;
            } else {
                pj->next = pi->next;
                pi->next = pi->next->next;
                pj = pj->next;
            }
        }
        pi->next = fake2.next;
        pj->next = NULL;
        return fake1.next;
    }
};