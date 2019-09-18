// LeetCode 52 N-Queens II.cpp

class Solution {
public:
    int totalNQueens(int n) {
        vector<bool> att(5 * n + 2);
        return backtrack(att, n, 0);
    }
    
private:
    int backtrack(vector<bool> &att, int n, int r) {
        if (r >= n) return 1;
        int total = 0;
        for (int c = 0; c < n; c++) {
            int ul = c - r + n - 1;
            int u  = 2 * n + 1 + c;
            int ur = 3 * n + 1 + r + c;
            if (!(att[ul] || att[u] || att[ur])) {
                att[ul] = att[u] = att[ur] = true;
                total += backtrack(att, n, r + 1);
                att[ul] = att[u] = att[ur] = false;
            }
        }
        return total;
    }
};