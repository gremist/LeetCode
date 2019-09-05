// LeetCode 216 Combination Sum III.cpp

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> cur(k);
        backtrack(ans, cur, k, n, 9);
        return ans;
    }
    
private:
    void backtrack(vector<vector<int>> &ans, vector<int> &cur, int k, int n, int di) {
        if (k == 0 && n == 0) ans.push_back(cur);
        if (k <= 0 || n <= 0) return;
        for (int i = di; i >= k; i--) {
            cur[cur.size() - k] = i;
            backtrack(ans, cur, k - 1, n - i, i - 1);
        }
    }
};