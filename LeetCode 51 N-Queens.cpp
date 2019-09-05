// LeetCode 51 N-Queens.cpp

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<int> cur(n);
        vector<bool> att(5 * n + 2, false);
        backtrack(ans, cur, att, n, 0);
        return ans;
    }

private:
    void backtrack(vector<vector<string>> &ans, vector<int> &cur, vector<bool> &att, int n, int r) {
        if (r >= n) {
            ans.emplace_back(n, string(n, '.'));
            for (int i = 0; i < n; i++) {
                ans.back()[i][cur[i]] = 'Q';
            }
            return;
        }
        for (int c = 0; c < n; c++) {
            int ul = c - r + n - 1;
            int u  = 2 * n + 1 + c;
            int ur = 3 * n + 1 + r + c;
            if (!(att[ul] || att[u] || att[ur])) {
                cur[r] = c;
                att[ul] = att[u] = att[ur] = true;
                backtrack(ans, cur, att, n, r + 1);
                att[ul] = att[u] = att[ur] = false;
            }
        }
    }
};