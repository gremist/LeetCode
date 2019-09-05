// LeetCode 160 Intersection of Two Linked Lists.cpp

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 方法1：双指针
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pa = headA, *pb = headB;
        while (pa != pb) {
            pa = pa ? pa->next : headB;
            pb = pb ? pb->next : headA;
        }
        return pa;
    }
};

// 方法2：哈希表
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode *> s;
        while (headA) {
            s.insert(headA);
            headA = headA->next;
        }
        while (headB) {
            if (s.find(headB) != s.end()) {
                return headB;
            }
            headB = headB->next;
        }
        return NULL;
    }
};