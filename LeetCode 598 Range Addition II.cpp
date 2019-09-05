// LeetCode 598 Range Addition II.cpp

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        for (vector<int> &op : ops) {
            m = min(op[0], m);
            n = min(op[1], n);
        }
        return m * n;
    }
};