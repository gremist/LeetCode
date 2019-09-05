// LeetCode 22 Generate Parentheses.cpp

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string cur(2 * n, '*');
        backtrack(ans, cur, n, 0, 0);
        return ans;
    }

private:
    void backtrack(vector<string> &ans, string &cur, int n, int l, int r) {
        if (l >= n && r >= n) {
            ans.push_back(cur);
            return;
        }
        if (l < n) {
            cur[l + r] = '(';
            backtrack(ans, cur, n, l + 1, r);
        }
        if (r < l) {
            cur[l + r] = ')';
            backtrack(ans, cur, n, l, r + 1);
        }
    }
};