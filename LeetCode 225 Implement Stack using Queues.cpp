// LeetCode 225 Implement Stack using Queues.cpp

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        queue<int> q;
        while (!revq.empty()) {
            q.push(revq.front());
            revq.pop();
        }
        revq.push(x);
        while (!q.empty()) {
            revq.push(q.front());
            q.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int x = revq.front();
        revq.pop();
        return x;
    }
    
    /** Get the top element. */
    int top() {
        return revq.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return revq.empty();
    }

private:
    queue<int> revq;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */