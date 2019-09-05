// LeetCode 23 Merge k Sorted Lists.cpp

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 方法1：暴力法，T(n) = O(nlogn)，S(n) = O(n)
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode *> nodes;
        for (ListNode *pi : lists) {
            while (pi) {
                nodes.push_back(pi);
                pi = pi->next;
            }
        }
        
        sort(nodes.begin(), nodes.end(),
            [] (ListNode *a, ListNode *b) { return a->val < b->val; });
        
        ListNode fake(0), *tail = &fake;
        for (ListNode *pi : nodes) {
            tail->next = pi;
            tail = tail->next;
        }
        tail->next = NULL;
        return fake.next;
    }
};

// 方法2：分治法，T(n) = O(nlogk)，S(n) = O(1)
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return NULL;
        for (int itv = 1; itv < lists.size(); itv *= 2) {
            for (int i = 0; i + itv < lists.size(); i += itv * 2) {
                lists[i] = mergeTwoLists(lists[i], lists[i + itv]);
            }
        }
        return lists[0];
    }

private:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode fake(0), *pLast = &fake;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                pLast->next = l1;
                l1 = l1->next;
            } else {
                pLast->next = l2;
                l2 = l2->next;
            }
            pLast = pLast->next;
        }
        pLast->next = l1 ? l1 : l2;
        return fake.next;
    }
};

// 方法3：逐个比较，T(n) = O(kn)，S(n) = O(1)
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for (auto it = lists.begin(); it != lists.end(); ) {
            it = !*it ? lists.erase(it) : it + 1;
        }
        
        ListNode fake(0), *plast = &fake;
        while (!lists.empty()) {
            auto it = min_element(lists.begin(), lists.end(),
                [] (ListNode *a, ListNode *b) { return a->val < b->val; });
            
            plast->next = *it;
            plast = plast->next;
            
            *it = (*it)->next;
            if (!*it) {
                lists.erase(it);
            }
        }
        return fake.next;
    }
};