// LeetCode 703 Kth Largest Element in a Stream.cpp

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) : k(k) {
        for (int n : nums) {
            add(n);
        }
    }
    
    int add(int val) {
        q.push(val);
        if (q.size() > k) {
            q.pop();
        }
        return q.top();
    }
    
private:
    int k;
    priority_queue<int, vector<int>, greater<int>> q;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */