// LeetCode 1046 Last Stone Weight.cpp

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;
        for (int s : stones) {
            q.push(s);
        }
        while (q.size() > 1) {
            int s1 = q.top();
            q.pop();
            int s2 = q.top();
            q.pop();
            if (s1 - s2) {
                q.push(s1 - s2);
            }
        }
        return q.empty() ? 0 : q.top();
    }
};