// LeetCode 138 Copy List with Random Pointer.cpp

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/

// 方法1：哈希表
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;        
        unordered_map<Node *, Node *> m;
        
        Node *pi = head;
        while (pi) {
            m[pi] = new Node(pi->val, NULL, NULL);
            pi = pi->next;
        }
        
        pi = head;
        while (pi) {
            m[pi]->next = m[pi->next];
            m[pi]->random = m[pi->random];
            pi = pi->next;
        }
        return m[head];
    }
};

// 方法2：有丝分裂
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;        
        
        Node *pi = head;
        while (pi) {
            Node *cn = new Node(pi->val, pi->next, NULL);
            pi->next = cn;
            pi = cn->next;
        }
        
        pi = head;
        while (pi) {
            if (pi->random) {
                pi->next->random = pi->random->next;
            }
            pi = pi->next->next;
        }
        
        pi = head;
        head = head->next;
        while (pi->next) {
            Node *cn = pi->next;
            pi->next = cn->next;
            pi = cn;
        }
        return head;
    }
};