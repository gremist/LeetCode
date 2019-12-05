// LeetCode 382 Linked List Random Node.cpp

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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) : dre(time(0)), head(head) {
        
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int ans, n = 0;
        for (ListNode *pi = head; pi; pi = pi->next) {
            uniform_int_distribution<int> uid(0, n++);
            if (!uid(dre)) {
                ans = pi->val;
            }
        }
        return ans;
    }
    
private:
    default_random_engine dre;
    ListNode *head;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */