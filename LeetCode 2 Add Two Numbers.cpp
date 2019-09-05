// LeetCode 2 Add Two Numbers.cpp

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode fake(0), *pi = &fake;
        int carry = 0;
        
        while ( l1 || l2 || carry ) {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = sum / 10;   // 保存进位
            
            pi->next = new ListNode(sum % 10);
            pi = pi->next;
            
            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
        }
        return fake.next;
    }
};