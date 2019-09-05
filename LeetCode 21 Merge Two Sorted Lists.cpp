// LeetCode 21 Merge Two Sorted Lists.cpp

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode fake(0), *last = &fake;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                last->next = l1;
                l1 = l1->next;
            } else {
                last->next = l2;
                l2 = l2->next;
            }
            last = last->next;
        }
        last->next = l1 ? l1 : l2;
        return fake.next;
    }
};

// 方法2：递归
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l2->next, l1);
            return l2;
        }
    }
};