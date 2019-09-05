// LeetCode 622 Design Circular Queue.cpp

class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) : v(k + 1) {

    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        v[rear] = value;
        rear = (rear + 1) % v.size();
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        front = (front + 1) % v.size();
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return v[front];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return v[(rear + v.size() - 1) % v.size()];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return front == rear;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return front == (rear + 1) % v.size();
    }
    
private:
    vector<int> v;
    int front = 0, rear = 0;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */