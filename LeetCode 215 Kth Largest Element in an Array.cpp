// LeetCode 215 Kth Largest Element in an Array.cpp

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q;
        for (int n : nums) {
            q.push(n);
        }
        for (int i = 0; i < k - 1; i++) {
            q.pop();
        }
        return q.top();
    }
};