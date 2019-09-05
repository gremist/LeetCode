// LeetCode 206 Reverse Linked List.cpp

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 方法1：迭代，T(n) = O(n)，S(n) = O(1)
// 指针赋值n次，已翻转部分末尾直接指向原链表末尾
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *pa = NULL;
        while (head) {
            ListNode *pb = head->next;
            head->next = pa;
            pa = head;
            head = pb;
        }
        return pa;
    }
};

// 方法2：迭代，T(n) = O(n)，S(n) = O(1)
// 指针赋值2 * (n - 1)次，已翻转部分末尾指向未反转部分头结点
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return NULL;
        ListNode *pa = head;
        while (head->next) {
            ListNode *pb = head->next;
            head->next = pb->next;
            pb->next = pa;
            pa = pb;
        }
        return pa;
    }
};

// 方法3：递归，T(n) = O(n)，S(n) = O(n)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *pa = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return pa;
    }
};