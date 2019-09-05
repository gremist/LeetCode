// LeetCode 19 Remove Nth Node From End of List.cpp

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode fake(0);
        fake.next = head;
        
        ListNode *front = &fake, *back = &fake;
        while (n--) {
            front = front->next;
        }
        while (front->next != NULL) {
            front = front->next;
            back = back->next;
        }
        
        front = back->next;
        back->next = front->next;
        delete front;
        
        return fake.next;
    }
};