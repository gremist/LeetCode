// LeetCode 77 Combinations.cpp

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> cur(k);
        backtrack(ans, cur, n, k);
        return ans;
    }
    
private:
    void backtrack(vector<vector<int>> &ans, vector<int> &cur, int n, int k) {
        if (k <= 0) {
            ans.push_back(cur);
            return;
        }
        for (int i = n; i >= k; i--) {
            cur[cur.size() - k] = i;
            backtrack(ans, cur, i - 1, k - 1);
        }
    }
};