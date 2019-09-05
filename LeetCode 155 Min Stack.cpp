// LeetCode 155 Min Stack.cpp

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if (vs.empty() || x <= mins.top()) {
            mins.push(x);
        }
        vs.push(x);
    }
    
    void pop() {
        if (vs.top() == mins.top()) {
            mins.pop();
        }
        vs.pop();
    }
    
    int top() {
        return vs.top();
    }
    
    int getMin() {
        return mins.top();
    }

private:
    stack<int> vs;
    stack<int> mins;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */