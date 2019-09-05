// LeetCode 232 Implement Queue using Stacks.cpp

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stack<int> s;
        while (!revs.empty()) {
            s.push(revs.top());
            revs.pop();
        }
        revs.push(x);
        while (!s.empty()) {
            revs.push(s.top());
            s.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int x = revs.top();
        revs.pop();
        return x;
    }
    
    /** Get the front element. */
    int peek() {
        return revs.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return revs.empty();
    }

private:
    stack<int> revs;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */