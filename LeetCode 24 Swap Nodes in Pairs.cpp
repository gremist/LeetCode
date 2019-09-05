// LeetCode 24 Swap Nodes in Pairs.cpp

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 方法1：递归
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *pa = head->next;
        head->next = swapPairs(pa->next);
        pa->next = head;
        return pa;
    }
};

// 方法2：迭代
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode fake(0);
        fake.next = head;
        
        ListNode *pa = &fake;
        while (head && head->next) {
            pa->next = head->next;
            head->next = pa->next->next;
            pa->next->next = head;
            pa = head;
            head = pa->next;
        }
        return fake.next;
    }
};